#pragma once

#include "..\Common.h"
#include "..\Utilities\GameTimer.h"

#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace App {

	class GE_API GameWindow
	{
	public:
		GameWindow(unsigned int width, unsigned int height, const std::string& title);
		~GameWindow();

		static GameWindow* Instance();

		void Run();

		void Terminate();
		void DisableCursor(bool value = true);
		void SetTitle(const std::string& title);
		void SetClearColour(float r, float g, float b, float a);

		GLFWwindow* const GetGLFWWindow() const;
		int GetHeight() const;
		int GetWidth() const;
		const Utilities::GameTimer& GetGameTimer() const;
	protected:
		virtual void OnLoad();
		virtual void OnUpdateFrame();
		virtual void OnRenderFrame();
	protected:
		bool Initialise();
		bool Closed();
		void PollEvents();
		void SwapBuffers();
	private:
		static GameWindow* m_pInstance;

		unsigned int m_Width = 800;
		unsigned int m_Height = 600;
		std::string m_Title = "Game Window";
		GLFWwindow* m_pWindow = nullptr;
		float m_ClearColour[4] = { 0.95f, 0.95f, 0.95f, 1.0f };

		Utilities::GameTimer m_GameTimer;
	};

}

#define GAME_WINDOW App::GameWindow::Instance()