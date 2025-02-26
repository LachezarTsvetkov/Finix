#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Finix {

	class FINIX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// TO DO in CLIENT
	Application* CreateApplication();
}
