#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Finix {

	class FINIX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	// TO DO in CLIENT
	Application* CreateApplication();
}
