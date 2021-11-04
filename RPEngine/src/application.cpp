
#include "application.h"



void Program(void* window)
{
	#if 1
	rpe::Application* app = new rpe::Application(window);
	app->Run();
	delete app;
	app = nullptr;
	#endif
}


void IsRunning(bool running)
{
	if (!running)
	{
		
	}
}

rpe::Application::Application(void* window)
{
	//wnd = Window::Create(1600, 900, L"RainyPlains");
	//d3d11r = new D3D11Renderer((Window*)window);
	//InitImGui();
}

void rpe::Application::Run()
{
	while (true)
	{
		//d3d11r->DrawTriangle();


		/*
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(800, 600));
		ImGui::Begin("Test");
		ImGui::End();
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		*/

		d3d11r->SwapBuffers();
	}
}

void rpe::Application::InitImGui()
{
}

void rpe::Application::DestroyImGui()
{
}

rpe::Application::~Application()
{
	/*
	DestroyImGui();
	Window::Destroy(wnd);
	*/
	delete d3d11r;
	d3d11r = nullptr;
}

void SetBackgroundColor(double r, double g, double b)
{
	rpe::Application::m_r = r;
	rpe::Application::m_g = g;
	rpe::Application::m_b = b;
}

double rpe::Application::m_r;
double rpe::Application::m_g;
double rpe::Application::m_b;
