#include "d3d11renderer.h"



rpe::D3D11Renderer::D3D11Renderer(void* window) :
	m_device(nullptr),
	m_swapChain(nullptr),
	m_context(nullptr),
	m_target(nullptr),
	m_backBuffer(nullptr),
	m_window(window),
	m_width(0),
	m_height(0)
{
	DXGI_SWAP_CHAIN_DESC sd = { };
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.OutputWindow = (HWND)window;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;
	RP_HRESULT_CHECK(D3D11CreateDeviceAndSwapChain(nullptr,
											D3D_DRIVER_TYPE_HARDWARE,
											nullptr,
											0,
											nullptr,
											0,
											D3D11_SDK_VERSION,
											&sd,
											&m_swapChain,
											&m_device,
											nullptr,
		&m_context));

	RP_HRESULT_CHECK(m_swapChain->GetBuffer(0, __uuidof(ID3D11Resource), &m_backBuffer));
	RP_HRESULT_CHECK(m_device->CreateRenderTargetView(m_backBuffer.Get(), nullptr, &m_target));
}

void rpe::D3D11Renderer::SwapBuffers()
{
	RP_HRESULT_CHECK(m_swapChain->Present(1, 0));
}

void rpe::D3D11Renderer::ClearBuffer(u8 red, u8 green, u8 blue)
{
	const float color[] = { red / 255, green / 255, blue / 255, 1.0f };
	m_context->ClearRenderTargetView(m_target.Get(), color);
}

rpe::D3D11Renderer::~D3D11Renderer()
{}

void rpe::D3D11Renderer::DrawTriangle(Vertex vert1, Vertex vert2, Vertex vert3)
{
	namespace wrl = Microsoft::WRL;

	const Vertex vertices[] =
	{
		vert1,
		vert2,
		vert3
	};
	wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
	D3D11_BUFFER_DESC bd = {};
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0u;
	bd.MiscFlags = 0u;
	bd.ByteWidth = sizeof(vertices);
	bd.StructureByteStride = sizeof(Vertex);
	D3D11_SUBRESOURCE_DATA sd = {};
	sd.pSysMem = vertices;
	RP_HRESULT_CHECK(m_device->CreateBuffer(&bd, &sd, &pVertexBuffer));
	// Bind vertex buffer to pipeline
	const UINT stride = sizeof(Vertex);
	const UINT offset = 0u;
	m_context->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);

	// create pixel shader
	wrl::ComPtr<ID3D11PixelShader> pPixelShader;
	wrl::ComPtr<ID3DBlob> pBlob;
	RP_HRESULT_CHECK(D3DReadFileToBlob(L"PixelShader.cso", &pBlob));
	RP_HRESULT_CHECK(m_device->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));
	// bind pixel shader
	m_context->PSSetShader(pPixelShader.Get(), nullptr, 0u);
	// create vertex shader
	wrl::ComPtr<ID3D11VertexShader> pVertexShader;
	RP_HRESULT_CHECK(D3DReadFileToBlob(L"VertexShader.cso", &pBlob));
	RP_HRESULT_CHECK(m_device->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));
	// bind vertex shader
	m_context->VSSetShader(pVertexShader.Get(), nullptr, 0u);

	// input (vertex) layout (2d position only)
	wrl::ComPtr<ID3D11InputLayout> pInputLayout;
	const D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
		{ "Color",0,DXGI_FORMAT_R32G32B32_FLOAT,0,8u,D3D11_INPUT_PER_VERTEX_DATA,0 },
	};
	RP_HRESULT_CHECK(m_device->CreateInputLayout(
		ied, (UINT)std::size(ied),
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		&pInputLayout
	));
	// bind vertex layout
	m_context->IASetInputLayout(pInputLayout.Get());
	// bind render target
	m_context->OMSetRenderTargets(1u, m_target.GetAddressOf(), nullptr);
	// Set primitive topology to triangle list (groups of 3 vertices)
	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// configure viewport
	D3D11_VIEWPORT vp;
	vp.Width = m_width;
	vp.Height = m_height;
	vp.MinDepth = 0;
	vp.MaxDepth = 1;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_context->RSSetViewports(1u, &vp);
	m_context->Draw((UINT)std::size(vertices), 0u);

	pVertexBuffer.ReleaseAndGetAddressOf();
	pVertexShader.ReleaseAndGetAddressOf();
	pBlob.ReleaseAndGetAddressOf();
	pPixelShader.ReleaseAndGetAddressOf();
	pInputLayout.ReleaseAndGetAddressOf();
}

void rpe::D3D11Renderer::ResizeBuffer(u16 width, u16 height)
{
	m_width = width;
	m_height = height;
	ID3D11RenderTargetView* rtw = { };
	m_context->OMSetRenderTargets(1, &rtw, 0);
	m_target.ReleaseAndGetAddressOf();
	m_backBuffer.ReleaseAndGetAddressOf();
	m_context->Flush();
	RP_HRESULT_CHECK(m_swapChain->ResizeBuffers(1, m_width, m_height, DXGI_FORMAT_R8G8B8A8_UNORM, 0));
	RP_HRESULT_CHECK(m_swapChain->GetBuffer(0, __uuidof(ID3D11Resource), &m_backBuffer));
	RP_HRESULT_CHECK(m_device->CreateRenderTargetView(m_backBuffer.Get(), nullptr, &m_target));
}
