#include "d3d11renderer.h"

rpe::D3D11Renderer::D3D11Renderer(w32_window* window) : m_device(nullptr), m_swapChain(nullptr), m_context(nullptr)
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
	sd.OutputWindow = window->m_wndHandle;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;
	D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &sd, &m_swapChain, &m_device, nullptr, &m_context);
	ID3D11Resource* backBuffer = nullptr;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&backBuffer));
}

void rpe::D3D11Renderer::SwapBuffers()
{
	m_swapChain->Present(1, 0);
}

rpe::D3D11Renderer::~D3D11Renderer()
{
	if (m_swapChain != nullptr) m_swapChain->Release();
	if (m_device != nullptr) m_device->Release();
	if (m_context != nullptr) m_context->Release();
}
