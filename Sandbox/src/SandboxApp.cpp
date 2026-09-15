#include <Finix.h>

class ExampleLayer : public Finix::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FX_INFO("ExampleLayer::Update");
	}

	void OnEvent(Finix::Event& event) override
	{
		FX_TRACE("{0}", event);
	}

};

class Sandbox : public Finix::Application
{
public:
	Sandbox()
	{ 
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Finix::Application* Finix::CreateApplication()
{
	return new Sandbox();
}