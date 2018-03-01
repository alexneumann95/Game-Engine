#include "EntityManager.h"

namespace Managers {

	EntityManager* EntityManager::m_pInstance = nullptr;

	EntityManager::EntityManager()
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;
	}

	EntityManager* EntityManager::Instance()
	{
		return m_pInstance;
	}

	bool EntityManager::Start()
	{
		// Create a default camera
		SetActiveCamera(AddEntity(Camera()));

		return true;
	}

	bool EntityManager::Stop()
	{
		for (auto iter : m_Entities)
			delete iter.second;
		m_Entities.clear();

		return true;
	}

	void EntityManager::Update()
	{
		for (auto iter : m_Entities)
			iter.second->Update();
	}

	const EntitiesMap& EntityManager::GetEntities() const
	{
		return m_Entities;
	}

	void EntityManager::SetActiveCamera(const std::string& EUID)
	{
		if (CheckEntityExists(EUID) && m_Entities.find(EUID)->second->GetType() == EntityType::CAMERA)
			m_ActiveCameraEUID = EUID;
		else
			LogError("Camera is not found!");
	}

	Camera* const EntityManager::GetActiveCamera() const
	{
		return dynamic_cast<Camera*>(m_Entities.find(m_ActiveCameraEUID)->second);
	}

	const std::string& EntityManager::AddEntity(const Entity& entity)
	{
		if (CheckEntityExists(entity.GetEUID()))
			return m_Entities.find(entity.GetEUID())->first;

		std::pair<EntitiesMap::iterator, bool> result = m_Entities.insert(std::pair<std::string, Entity*>(entity.GetEUID(), entity.Clone()));
		result.first->second->Start();
		if (entity.GetType() == EntityType::GAME_OBJECT)
			dynamic_cast<GameObject*>(result.first->second)->InitComponents();
		return result.first->first;
	}

	bool EntityManager::CheckEntityExists(const std::string& EUID)
	{
		auto iter = m_Entities.find(EUID);
		return (iter != m_Entities.end()) ? true : false;
	}

	bool EntityManager::DestroyEntity(const std::string& EUID)
	{
		if (!CheckEntityExists(EUID))
			return false;

		auto iter = m_Entities.find(EUID);
		delete iter->second;
		m_Entities.erase(iter);

		return true;
	}

}