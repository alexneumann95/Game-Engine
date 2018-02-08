#pragma once

#include "..\Common.h"

#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace App {

	class API GameWindow final
	{
	public:
		GameWindow(unsigned int width, unsigned int height, const char* title);
		~GameWindow();

		bool Initialise();
		bool Closed();
		void PollEvents();
		void SwapBuffers();
	private:
		unsigned int m_Width = 800;
		unsigned int m_Height = 600;
		const char* m_Title = "Game Window";
		GLFWwindow* m_Window = nullptr;
	};

}