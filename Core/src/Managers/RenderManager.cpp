#include "RenderManager.h"
#include "ShaderManager.h"
#include "EntityManager.h"
#include "..\App\GameWindow.h"


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
			pGameObject->GetModelComp()->GetTexture()->Bind();

			mat4<float> modelMatrix = pGameObject->GetTransformComp()->GetModelMatrix();
			SHADER_MANAGER->GetShader()->SetUniform("vModel", modelMatrix);
			mat4<float> viewMatrix = ENTITY_MANAGER->GetActiveCamera()->GetViewMatrix();
			SHADER_MANAGER->GetShader()->SetUniform("vView", viewMatrix);
			mat4<float> projMatrix = ENTITY_MANAGER->GetActiveCamera()->GetPerspectiveMatrix();
			SHADER_MANAGER->GetShader()->SetUniform("vProj", projMatrix);	

			glDrawElements(GL_TRIANGLES, pGameObject->GetModelComp()->GetModel()->GetNumIndices(), GL_UNSIGNED_INT, nullptr);

			pGameObject->GetModelComp()->GetTexture()->Unbind();
			pGameObject->GetRenderComp()->GetElementBuffer()->UnbindEBO();
			pGameObject->GetRenderComp()->GetVertexBuffer()->UnbindVAO();	
		}
	}

}