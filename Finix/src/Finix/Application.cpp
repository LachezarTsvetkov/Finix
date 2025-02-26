#include "Application.h"
#include "Finix/Events/ApplicationEvent.h"


#include "Finix/Log.h"
namespace Finix {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FX_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FX_TRACE(e.ToString());
		}
		while (true);
	}
}