#pragma once
#include "../PaperPixelCore.h"
#include "Renderer.h"

namespace pp
{

struct AppProps
{
	int Width = 800, Height = 600;
	int MinWidth = 640, MinHeight = 480;
	const char* Title = "PaperPixel";
};

class PP_API Application
{
public:
	Application(const AppProps& props = AppProps());
	virtual ~Application();
	bool IsCreated() const;
	void Run();
protected:
	void SetTitle(const char* title);
	void SetIcon(const char* iconpath, bool vflip = false);
	// Called once before the application loop
	virtual void OnCreate();
	// Called once per frame
	virtual void OnUpdate(float delta);
	// Called once per frame
	virtual void OnRender(Renderer renderer);
protected:
	AppProps m_Props;
private:
	GLFWwindow* m_Window;
	Renderer m_Renderer;
	bool m_Created;
};

}