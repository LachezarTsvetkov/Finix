#pragma once

#include "Core.h"

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
