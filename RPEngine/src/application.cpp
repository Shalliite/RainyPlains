#include "application.h"

rpe::Application::Application()
{
	m_wnd = new w32_window(1600, 900, L"RPE");
}

void rpe::Application::Run()
{
	MSG message;
	while (GetMessage(&message, 0, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

rpe::Application::~Application()
{}