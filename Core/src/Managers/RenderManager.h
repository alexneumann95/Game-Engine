#pragma once

#include "Manager.h"

namespace Managers {

	class GE_API RenderManager final : public Manager
	{
	public:
		RenderManager();
		static RenderManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;
	private:
		static RenderManager* m_pInstance;
	};

}