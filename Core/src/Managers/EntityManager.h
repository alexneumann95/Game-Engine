#pragma once

#include "Manager.h"

namespace Managers {

	class GE_API EntityManager final : public Manager
	{
	public:
		EntityManager();
		static EntityManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;
	private:
		static EntityManager* m_pInstance;
	};

}