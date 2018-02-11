#pragma once

#include "Manager.h"

#include <glad\glad.h>

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