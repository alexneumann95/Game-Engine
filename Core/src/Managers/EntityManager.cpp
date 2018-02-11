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
		return true;
	}

	bool EntityManager::Stop()
	{
		for (auto iter : m_GameObjects)
			delete iter.second;
		m_GameObjects.clear();

		return true;
	}

	void EntityManager::Update()
	{
		for (auto iter : m_GameObjects)
			iter.second->Update();
	}

	const GameObjectsMap& EntityManager::GetGameObjects() const
	{
		return m_GameObjects;
	}

	const std::string& EntityManager::AddGameObject(const GameObject& object)
	{
		if (CheckGameObjectExists(object.GetEUID()))
			return m_GameObjects.find(object.GetEUID())->first;

		std::pair<GameObjectsMap::iterator, bool> result = m_GameObjects.insert(std::pair<std::string, GameObject*>(object.GetEUID(), object.Clone()));
		result.first->second->Start();
		result.first->second->InitComponents();
		return result.first->first;
	}

	bool EntityManager::CheckGameObjectExists(const std::string& EUID)
	{
		auto iter = m_GameObjects.find(EUID);
		return (iter != m_GameObjects.end()) ? true : false;
	}

	bool EntityManager::DestroyGameObject(const std::string& EUID)
	{
		if (!CheckGameObjectExists(EUID))
			return false;

		auto iter = m_GameObjects.find(EUID);
		delete iter->second;
		m_GameObjects.erase(iter);

		return true;
	}

}