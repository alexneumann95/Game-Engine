#pragma once

#include "Manager.h"
#include "..\Entities\EntityType.h"
#include "..\Entities\GameObject.h"
#include "..\Entities\Camera.h"
#include "..\Entities\Lights\DirectionalLight.h"

#include <map>

using namespace Entities;
using namespace Lights;

typedef std::map<std::string, Entity*> EntitiesMap;

namespace Managers {

	class GE_API EntityManager final : public Manager
	{
	public:
		EntityManager();
		static EntityManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		const EntitiesMap& GetEntities() const;

		void SetActiveCamera(const std::string& EUID);
		Camera* const GetActiveCamera() const;

		const std::string& AddEntity(const Entity& entity);

		bool CheckEntityExists(const std::string& EUID);
		bool DestroyEntity(const std::string& EUID);
	private:
		static EntityManager* m_pInstance;
		EntitiesMap m_Entities;
		std::string m_ActiveCameraEUID = "";	
	};

}

#define ENTITY_MANAGER Managers::EntityManager::Instance()