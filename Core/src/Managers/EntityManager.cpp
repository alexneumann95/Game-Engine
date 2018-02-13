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
		std::string camID = AddCamera(Camera());
		SetActiveCamera(camID);

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

		for (auto iter : m_Cameras)
			iter.second->Update();
	}

	const GameObjectsMap& EntityManager::GetGameObjects() const
	{
		return m_GameObjects;
	}

	void EntityManager::SetActiveCamera(const std::string& EUID)
	{
		if (CheckCameraExists(EUID))
			m_ActiveCameraEUID = EUID;
	}

	Camera* const EntityManager::GetActiveCamera() const
	{
		return m_Cameras.find(m_ActiveCameraEUID)->second;
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

	const std::string& EntityManager::AddCamera(const Camera& cam)
	{
		if (CheckCameraExists(cam.GetEUID()))
			return m_Cameras.find(cam.GetEUID())->first;

		std::pair<CamerasMap::iterator, bool> result = m_Cameras.insert(std::pair<std::string, Camera*>(cam.GetEUID(), cam.Clone()));
		result.first->second->Start();
		return result.first->first;
	}

	bool EntityManager::CheckGameObjectExists(const std::string& EUID)
	{
		auto iter = m_GameObjects.find(EUID);
		return (iter != m_GameObjects.end()) ? true : false;
	}

	bool EntityManager::CheckCameraExists(const std::string& EUID)
	{
		auto iter = m_Cameras.find(EUID);
		return (iter != m_Cameras.end()) ? true : false;
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

	bool EntityManager::DestroyCamera(const std::string& EUID)
	{
		if (!CheckCameraExists(EUID))
			return false;

		auto iter = m_Cameras.find(EUID);
		delete iter->second;
		m_Cameras.erase(iter);

		return true;
	}

}