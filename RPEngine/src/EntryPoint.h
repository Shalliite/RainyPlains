#pragma once
#include "application.h"

#define rpImplementApp(x) rpe::Application* CreateApp() { return new x; }

namespace rpe
{
	extern rpe::Application* CreateApp();
}

void Program()
{
	rpe::Application* app = rpe::CreateApp();
	app->Run();
	delete app;
	app = nullptr;
}

#ifdef _DEBUG
int main()
{
	Program();
}
#else
int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
	Program();
}
#endif