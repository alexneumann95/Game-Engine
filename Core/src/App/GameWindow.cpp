#include "GameWindow.h"
#include "..\EngineControl.h"

namespace App {

	GameWindow::GameWindow(unsigned int width, unsigned int height, const std::string& title) : m_Width(width), m_Height(height), m_Title(title)
	{
		OnLoad();
	}

	GameWindow::~GameWindow()
	{
		glfwTerminate();
		EngineControl::EngineShutDown();
	}

	void GameWindow::Run()
	{
		while (!Closed())
		{
			PollEvents();

			OnUpdateFrame();
			OnRenderFrame();

			SwapBuffers();
		}
	}

	void GameWindow::OnLoad()
	{
		Initialise();
		EngineControl::EngineStartUp();
	}

	void GameWindow::OnUpdateFrame()
	{
		EngineControl::EngineUpdate();
	}

	void GameWindow::OnRenderFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);

		RENDER_MANAGER->Draw();
	}

	bool GameWindow::Initialise()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
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

		int flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback((GLDEBUGPROC)Utilities::GLDebugOutput, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
			std::cout << "DEBUG CONTEXT ENABLED" << std::endl;
		}

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

	void GameWindow::SetClearColor(float r, float g, float b, float a)
	{
		m_ClearColor[0] = r;
		m_ClearColor[1] = g;
		m_ClearColor[2] = b;
		m_ClearColor[3] = a;
	}

}