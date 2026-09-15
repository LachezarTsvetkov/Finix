#pragma once

#include "Core.h"
#include "Finix/LayerStack.h"
#include "Finix/Events/Event.h"
#include "Finix/Events/ApplicationEvent.h"

#include "Window.h"

namespace Finix {

	class FINIX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	// TO DO in CLIENT
	Application* CreateApplication();
}
