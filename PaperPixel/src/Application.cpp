#include "pch.h"
#include <PaperPixel/Application.h>

GLFWimage LoadGLFWImage(const char* filepath, bool verticalflip);

void CleanUpGLFWImage(GLFWimage& image);

namespace pp
{

Application::Application(const AppProps& props)
	: m_Created(false), m_Props(props)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height, "PaperPixel", nullptr, nullptr);
	if (m_Window == nullptr)
	{
		std::cout << "Failed to create OpenGL render context!" << std::endl;
		return;
	}
	glfwMakeContextCurrent(m_Window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to load OpenGL functions!" << std::endl;
		return;
	}
	glfwSwapInterval(1);
	glfwSetWindowSizeLimits(m_Window, props.MinWidth, props.MinHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwSetWindowUserPointer(m_Window, &m_Props);
	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			AppProps& props = *(AppProps*)(glfwGetWindowUserPointer(window));
			props.Width = std::max(width, props.MinWidth);
			props.Height = std::max(height, std::max(props.MinHeight, 1));
			glViewport(0, 0, width, height);
		}
	);
	m_Created = true;
}

Application::~Application()
{
	glfwTerminate();
}

bool Application::IsCreated() const
{
	return m_Created;
}

void Application::Run()
{
	OnCreate();
	float past = 0.0f;
	while (!glfwWindowShouldClose(m_Window))
	{
		float now = (float)glfwGetTime();
		float delta = now - past;
		past = now;
		glClear(GL_COLOR_BUFFER_BIT);
		OnUpdate(delta);
		OnRender(m_Renderer);
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
}

void Application::SetTitle(const char* title)
{
	m_Props.Title = title;
	glfwSetWindowTitle(m_Window, title);
}

void Application::SetIcon(const char* iconpath, bool vflip)
{
	try
	{
		GLFWimage icon = LoadGLFWImage(iconpath, vflip);
		glfwSetWindowIcon(m_Window, 1, &icon);
		CleanUpGLFWImage(icon);
	}
	catch (std::exception e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
}

void Application::OnCreate()
{
}

void Application::OnUpdate(float delta)
{
}

void Application::OnRender(Renderer renderer)
{
}

}

GLFWimage LoadGLFWImage(const char* filepath, bool verticalflip)
{
	GLFWimage image;
	int ch = 0;
	image.pixels = stbi_load(filepath, &image.width, &image.height, &ch, 4);
	if (image.pixels != nullptr)
	{
		return image;
	}
	else
	{
		std::string what = "Failed to load image: ";
		what += std::string(stbi_failure_reason());
		throw std::exception(what.c_str());
	}
}

void CleanUpGLFWImage(GLFWimage& image)
{
	stbi_image_free(image.pixels);
}