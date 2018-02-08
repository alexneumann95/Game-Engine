#include "GameWindow.h"

namespace App
{
	GameWindow::GameWindow(unsigned int width, unsigned int height, const char* title) : m_Width(width), m_Height(height), m_Title(title)
	{

	}

	GameWindow::~GameWindow()
	{

	}

	bool GameWindow::Initialise()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
		if (m_Window == NULL)
		{
			LogError("Failed to create GLFW window!");
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			LogError("Failed to initialise GLAD");
			return false;
		}

		glViewport(0, 0, m_Width, m_Height);

		return true;
	}

	bool GameWindow::Closed()
	{
		return glfwWindowShouldClose(m_Window) ? true : false;
	}

	void GameWindow::PollEvents()
	{
		glfwPollEvents();
	}

	void GameWindow::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}