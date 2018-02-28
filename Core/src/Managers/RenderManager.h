#pragma once

#include "Manager.h"

#include <MathsLib\Containers\mat4.h>
#include <glad\glad.h>

using Maths::Containers::mat4;

namespace Managers {

	class GE_API RenderManager final : public Manager
	{
	public:
		RenderManager();
		static RenderManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		void Draw();
	private:
		static RenderManager* m_pInstance;
	};

}

#define RENDER_MANAGER Managers::RenderManager::Instance()