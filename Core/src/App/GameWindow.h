#pragma once

#include "..\Common.h"

#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace App {

	class GE_API GameWindow
	{
	public:
		GameWindow(unsigned int width, unsigned int height, const std::string& title);
		~GameWindow();

		void Run();
	protected:
		virtual void OnLoad();
		virtual void OnUpdateFrame();
		virtual void OnRenderFrame();
	protected:
		bool Initialise();
		bool Closed();
		void PollEvents();
		void SwapBuffers();
		void SetClearColor(float r, float g, float b, float a);
	private:
		unsigned int m_Width = 800;
		unsigned int m_Height = 600;
		std::string m_Title = "Game Window";
		GLFWwindow* m_Window = nullptr;
		float m_ClearColor[4] = { 0.2f, 0.7f, 0.8f, 1.0f };
	};

}