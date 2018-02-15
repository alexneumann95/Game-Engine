#include "GameWindow.h"
#include "..\EngineControl.h"

namespace App {

	GameWindow* GameWindow::m_pInstance = nullptr;

	GameWindow::GameWindow(unsigned int width, unsigned int height, const std::string& title) : m_Width(width), m_Height(height), m_Title(title)
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;

		OnLoad();
	}

	GameWindow::~GameWindow()
	{
		glfwTerminate();
		EngineControl::EngineShutDown();
	}

	GameWindow* GameWindow::Instance()
	{
		return m_pInstance;
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

	void GameWindow::Terminate()
	{
		glfwSetWindowShouldClose(m_pWindow, true);
	}

	void GameWindow::DisableCursor(bool value)
	{
		if (value)
			glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		else
			glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void GameWindow::SetTitle(const std::string& title)
	{
		m_Title = title;
		glfwSetWindowTitle(m_pWindow, title.c_str());
	}

	GLFWwindow* const GameWindow::GetGLFWWindow() const
	{
		return m_pWindow;
	}

	int GameWindow::GetHeight() const
	{
		return m_Height;
	}

	int GameWindow::GetWidth() const
	{
		return m_Width;
	}

	const Utilities::GameTimer& GameWindow::GetGameTimer() const
	{
		return m_GameTimer;
	}

	void GameWindow::OnLoad()
	{
		Initialise();
		EngineControl::EngineStartUp();
	}

	void GameWindow::OnUpdateFrame()
	{
		EngineControl::EngineUpdate();
		m_GameTimer.Tick();
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

		m_pWindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
		if (m_pWindow == nullptr)
		{
			LogError("Failed to create GLFW window!");
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_pWindow);

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

		glfwSwapInterval(0);
		glEnable(GL_DEPTH_TEST);

		return true;
	}

	bool GameWindow::Closed()
	{
		return glfwWindowShouldClose(m_pWindow) ? true : false;
	}

	void GameWindow::PollEvents()
	{
		glfwPollEvents();
	}

	void GameWindow::SwapBuffers()
	{
		glfwSwapBuffers(m_pWindow);
	}

	void GameWindow::SetClearColor(float r, float g, float b, float a)
	{
		m_ClearColor[0] = r;
		m_ClearColor[1] = g;
		m_ClearColor[2] = b;
		m_ClearColor[3] = a;
	}

}