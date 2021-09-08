#include "d3d11renderer.h"

rpe::D3D11Renderer::D3D11Renderer(Window* window) : m_device(nullptr), m_swapChain(nullptr), m_context(nullptr), m_target(nullptr)
{
	DXGI_SWAP_CHAIN_DESC sd = { };
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = (HWND)window;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;
	D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &sd, &m_swapChain, &m_device, nullptr, &m_context);
	Microsoft::WRL::ComPtr<ID3D11Resource> backBuffer = nullptr;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Resource), &backBuffer);
	m_device->CreateRenderTargetView(backBuffer.Get(), nullptr, &m_target);
}

void rpe::D3D11Renderer::SwapBuffers()
{
	m_swapChain->Present(0, 0);
}

void rpe::D3D11Renderer::ClearBuffer(float red, float green, float blue)
{
	const float color[] = { red,green,blue,1.0f };
	m_context->ClearRenderTargetView(m_target.Get(), color);
}

rpe::D3D11Renderer::~D3D11Renderer()
{}

void rpe::D3D11Renderer::DrawTriangle()
{
	HRESULT hr;

	struct Vertex
	{
		float x;
		float y;
	};

	const Vertex vertices[] =
	{
		{0.0f,0.5f},
		{0.5f,-0.5f},
		{-0.5f,-0.5f}
	};

	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	D3D11_BUFFER_DESC bd = {};
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	bd.ByteWidth = sizeof(vertices);
	bd.StructureByteStride = sizeof(Vertex);
	D3D11_SUBRESOURCE_DATA sd = {};
	sd.pSysMem = vertices;
	m_device->CreateBuffer(&bd, &sd, &vertexBuffer);
	const UINT stride = sizeof(Vertex);
	const UINT offset = 0;
	m_context->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);



	//pixel shader
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	Microsoft::WRL::ComPtr<ID3DBlob> blob;
	D3DReadFileToBlob(L"PixelShader.cso", &blob);
	m_device->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, &pixelShader);
	m_context->PSSetShader(pixelShader.Get(), nullptr, 0);

	//vertex shader
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	D3DReadFileToBlob(L"VertexShader.cso", &blob);
	m_device->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, &vertexShader);
	m_context->VSSetShader(vertexShader.Get(), nullptr, 0);

	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
	const D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{"Position", 0, DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA, 0}
	};
	m_device->CreateInputLayout(ied, (UINT)std::size(ied), blob->GetBufferPointer(), blob->GetBufferSize(), &inputLayout);
	m_context->IASetInputLayout(inputLayout.Get());

	m_context->OMSetRenderTargets(1, m_target.GetAddressOf(), nullptr);

	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	D3D11_VIEWPORT vp;
	vp.Width = 1600;
	vp.Height = 900;
	vp.MinDepth = 0;
	vp.MaxDepth = 1;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_context->RSSetViewports(1, &vp);

	m_context->Draw(std::size(vertices), 0);
	RenderImGui();
}

void rpe::D3D11Renderer::RenderImGui()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("Test");
	ImGui::End();
	ImGui::Begin("Test2");
	ImGui::End();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
