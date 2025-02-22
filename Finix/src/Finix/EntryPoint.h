#pragma once


#ifdef FX_PLATFORM_WINDOWS

extern Finix::Application* Finix::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Finix::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Finix only supports Windows!
#endif