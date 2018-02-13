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
		SHADER_MANAGER->GetShader()->Use();

		for (auto iter : EntityManager::Instance()->GetGameObjects())
		{
			Entities::GameObject* pGameObject = iter.second;

			pGameObject->GetRenderComp()->GetVertexBuffer()->BindVAO();
			pGameObject->GetRenderComp()->GetElementBuffer()->BindEBO();

			Maths::mat4 model = Maths::mat4::Identity();
			Maths::mat4 view = ENTITY_MANAGER->GetActiveCamera()->GetViewMatrix();
			Maths::mat4 proj = ENTITY_MANAGER->GetActiveCamera()->GetPerspectiveMatrix();
			Maths::mat4 MVPMatrix = proj * view * model;
			SHADER_MANAGER->GetShader()->SetUniform("vMVPMatrix", MVPMatrix.Invert());

			glDrawElements(GL_TRIANGLES, pGameObject->GetModelComp()->GetModel()->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
		}
	}

}