#pragma once


#ifdef FX_PLATFORM_WINDOWS

extern Finix::Application* Finix::CreateApplication();

int main(int argc, char** argv)
{
	Finix::Log::Init();

	FX_CORE_WARN("Initialized Log!");
	int a = 5;
	FX_INFO("Hello! Var={0}", a);

	auto app = Finix::CreateApplication();
	app->Run();

	delete app;
}
#else
	#error Finix only supports Windows!
#endif