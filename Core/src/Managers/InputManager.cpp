#include "InputManager.h"

namespace Managers {

	InputManager* InputManager::m_pInstance = nullptr;
	bool InputManager::m_KeyStates[512] { false };
	bool InputManager::m_MouseButtonStates[10] { false };
	double InputManager::m_MouseXPos = 0.0;
	double InputManager::m_MouseYPos = 0.0;
	
	InputManager::InputManager()
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;
	}

	InputManager* InputManager::Instance()
	{
		return m_pInstance;
	}

	bool InputManager::Start()
	{
		m_MouseXPos = GAME_WINDOW->GetWidth() / 2;
		m_MouseYPos = GAME_WINDOW->GetHeight() / 2;

		glfwSetKeyCallback(GAME_WINDOW->GetGLFWWindow(), KeyCallback);
		glfwSetCursorPosCallback(GAME_WINDOW->GetGLFWWindow(), CursorPosCallback);
		glfwSetMouseButtonCallback(GAME_WINDOW->GetGLFWWindow(), MouseButtonCallback);

		return true;
	}

	bool InputManager::Stop()
	{
		return true;
	}

	void InputManager::Update()
	{
		
	}

	bool InputManager::GetKeyState(int key) const
	{
		return m_KeyStates[key];
	}

	bool InputManager::GetMouseButtonState(int button) const
	{
		return m_MouseButtonStates[button];
	}

	double InputManager::GetMouseXPos() const
	{
		return m_MouseXPos;
	}

	double InputManager::GetMouseYPos() const
	{
		return m_MouseYPos;
	}

	void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
			m_KeyStates[key] = true;
		if (action == GLFW_RELEASE)
			m_KeyStates[key] = false;
	}

	void InputManager::CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		m_MouseXPos = xpos;
		m_MouseYPos = ypos;
	}

	void InputManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (action == GLFW_PRESS)
			m_MouseButtonStates[button] = true;
		if (action == GLFW_RELEASE)
			m_MouseButtonStates[button] = false;
	}

}