
#include "EntryPoint.h"
#include "application.h"

rpe::Application::Application()
{
	wnd = Window::Create(1600, 900, L"RainyPlains");
	d3d11r = new D3D11Renderer(wnd);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplWin32_Init(wnd);
	ImGui_ImplDX11_Init(d3d11r->m_device.Get(), d3d11r->m_context.Get());
	ImGui::StyleColorsLight();
}

void rpe::Application::Run()
{
	MSG message;
	while (GetMessage(&message, 0, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
		d3d11r->SwapBuffers();
	}
}

rpe::Application::~Application()
{
	Window::Destroy(wnd);
}