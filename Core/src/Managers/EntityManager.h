#pragma once

#include "Manager.h"
#include "..\Entities\EntityType.h"
#include "..\Entities\GameObject.h"
#include "..\Entities\Lights\DirectionalLight.h"
#include "..\Entities\Lights\PointLight.h"
#include "..\Entities\Camera.h"

#include <map>
#include <vector>

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

		void SetActiveCamera(const std::string& EUID);
		Entities::Camera* const GetActiveCamera() const;

		const std::string& AddEntity(const Entities::Entity& entity);

		// Returns a specific entity based on its EUID and type
		template <typename Type>
		Type* const GetEntity(const std::string& EUID);
		// Returns a vector of all entities of a certain type
		template <typename Type>
		const std::vector<Type*> GetEntities();

		bool CheckEntityExists(const std::string& EUID);
		bool DestroyEntity(const std::string& EUID);
	private:
		static EntityManager* m_pInstance;
		EntitiesMap m_Entities;
		std::string m_ActiveCameraEUID = "";

		unsigned int m_CurrentNumDirLights = 0;
	};

}

#define ENTITY_MANAGER Managers::EntityManager::Instance()

template GE_API Entities::GameObject* const Managers::EntityManager::GetEntity<Entities::GameObject>(const std::string& EUID);
template GE_API Entities::Camera* const Managers::EntityManager::GetEntity<Entities::Camera>(const std::string& EUID);
template GE_API Entities::Lights::DirectionalLight* const Managers::EntityManager::GetEntity<Entities::Lights::DirectionalLight>(const std::string& EUID);
template GE_API Entities::Lights::PointLight* const Managers::EntityManager::GetEntity<Entities::Lights::PointLight>(const std::string& EUID);

template GE_API const std::vector<Entities::GameObject*> Managers::EntityManager::GetEntities<Entities::GameObject>();
template GE_API const std::vector<Entities::Camera*> Managers::EntityManager::GetEntities<Entities::Camera>();
template GE_API const std::vector<Entities::Lights::DirectionalLight*> Managers::EntityManager::GetEntities<Entities::Lights::DirectionalLight>();
template GE_API const std::vector<Entities::Lights::PointLight*> Managers::EntityManager::GetEntities<Entities::Lights::PointLight>();