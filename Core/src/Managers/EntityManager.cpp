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
		return true;
	}

	void EntityManager::Update()
	{

	}

}