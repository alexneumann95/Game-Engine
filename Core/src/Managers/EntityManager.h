#pragma once

#include "Manager.h"
#include "..\Entities\EntityType.h"
#include "..\Entities\GameObject.h"
#include "..\Entities\Lights\DirectionalLight.h"
#include "..\Entities\Camera.h"

#include <map>

typedef std::map<std::string, Entities::Entity*> EntitiesMap;

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
		Entities::Camera* const GetActiveCamera() const;

		const std::string& AddEntity(const Entities::Entity& entity);

		template <typename Type>
		Type* const GetEntity(const std::string& EUID);

		bool CheckEntityExists(const std::string& EUID);
		bool DestroyEntity(const std::string& EUID);
	private:
		static EntityManager* m_pInstance;
		EntitiesMap m_Entities;
		std::string m_ActiveCameraEUID = "";	
	};

}

#define ENTITY_MANAGER Managers::EntityManager::Instance()

template GE_API Entities::GameObject* const Managers::EntityManager::GetEntity<Entities::GameObject>(const std::string& EUID);
template GE_API Entities::Camera* const Managers::EntityManager::GetEntity<Entities::Camera>(const std::string& EUID);
template GE_API Entities::Lights::DirectionalLight* const Managers::EntityManager::GetEntity<Entities::Lights::DirectionalLight>(const std::string& EUID);