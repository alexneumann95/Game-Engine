#include "RenderManager.h"

namespace Managers {

	RenderManager* RenderManager::m_pInstance = nullptr;

	RenderManager::RenderManager()
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;
	}

	RenderManager* RenderManager::Instance()
	{
		return m_pInstance;
	}

	bool RenderManager::Start()
	{
		return true;
	}

	bool RenderManager::Stop()
	{
		return true;
	}

	void RenderManager::Update()
	{
	
	}

}