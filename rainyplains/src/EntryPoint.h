#pragma once
#include "application.h"

void Program()
{
	rpe::Application* app = new rpe::Application;
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