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
		SetActiveCamera(AddEntity(Entities::Camera()));

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

	void EntityManager::SetActiveCamera(const std::string& EUID)
	{
		if (CheckEntityExists(EUID) && m_Entities.find(EUID)->second->GetType() == Entities::EntityType::CAMERA)
			m_ActiveCameraEUID = EUID;
		else
			LogError("Camera is not found!");
	}

	Entities::Camera* const EntityManager::GetActiveCamera() const
	{
		return dynamic_cast<Entities::Camera*>(m_Entities.find(m_ActiveCameraEUID)->second);
	}

	const std::string& EntityManager::AddEntity(const Entities::Entity& entity)
	{
		if (CheckEntityExists(entity.GetEUID()))
			return m_Entities.find(entity.GetEUID())->first;

		std::pair<EntitiesMap::iterator, bool> result = m_Entities.insert(std::pair<std::string, Entities::Entity*>(entity.GetEUID(), entity.Clone()));
		result.first->second->Start();
		result.first->second->InitComponents();
		return result.first->first;
	}

	template <typename Type>
	Type* const EntityManager::GetEntity(const std::string& EUID)
	{
		auto iter = m_Entities.find(EUID);
		return (iter != m_Entities.end()) ? dynamic_cast<Type* const>(iter->second) : nullptr;
	}

	template <typename Type>
	const std::vector<Type*> EntityManager::GetEntities()
	{
		auto pEntity = dynamic_cast<Entities::Entity*>(&Type());
		std::vector<Type*> result;

		for (auto entity : m_Entities)
			if (entity.second->GetType() == pEntity->GetType())
				result.push_back(dynamic_cast<Type*>(entity.second));

		return result;
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