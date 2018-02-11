#include "RenderManager.h"
#include "ShaderManager.h"
#include "EntityManager.h"

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

	void RenderManager::Draw()
	{
		ShaderManager::Instance()->GetShader()->Use();

		for (auto iter : EntityManager::Instance()->GetGameObjects())
		{
			Entities::GameObject* pGameObject = iter.second;

			pGameObject->GetRenderComp()->GetVertexBuffer()->BindVAO();
			pGameObject->GetRenderComp()->GetElementBuffer()->BindEBO();

			glDrawElements(GL_TRIANGLES, pGameObject->GetModelComp()->GetModel()->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
		}
	}

}