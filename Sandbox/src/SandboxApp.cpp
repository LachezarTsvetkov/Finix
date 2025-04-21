#include <Finix.h>


class Sandbox : public Finix::Application
{
public:
	Sandbox()
	{ 

	}

	~Sandbox()
	{

	}
};

Finix::Application* Finix::CreateApplication()
{
	return new Sandbox();
}