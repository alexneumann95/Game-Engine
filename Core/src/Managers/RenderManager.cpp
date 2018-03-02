#include "RenderManager.h"
#include "ShaderManager.h"
#include "EntityManager.h"
#include "ResourceManager.h"
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

		for (auto* pGameObject : ENTITY_MANAGER->GetEntities<Entities::GameObject>())
		{
			// Get RUIDs for all required resources
			auto vbRUID = pGameObject->GetComponent<Components::CRender>()->GetVertexBufferRUID();
			auto ebRUID = pGameObject->GetComponent<Components::CRender>()->GetElementBufferRUID();
			auto modelRUID = pGameObject->GetComponent<Components::CModel>()->GetModelRUID();
			auto meshesTextureRUIDS = pGameObject->GetComponent<Components::CModel>()->GetMeshesTextureRUIDS();

			// Bind buffers
			RESOURCE_MANAGER->GetVertexBuffer(vbRUID)->BindVAO();
			RESOURCE_MANAGER->GetElementBuffer(ebRUID)->BindEBO();

			// Set camera uniforms
			mat4<float> viewMatrix = ENTITY_MANAGER->GetActiveCamera()->GetViewMatrix();
			mat4<float> projMatrix = ENTITY_MANAGER->GetActiveCamera()->GetPerspectiveMatrix();
			mat4<float> modelMatrix = pGameObject->GetComponent<Components::CTransform>()->GetModelMatrix();
			SHADER_MANAGER->GetShader()->SetUniform("vMVPMatrix", projMatrix * viewMatrix * modelMatrix);

			// Set light uniforms
			SHADER_MANAGER->GetShader()->SetUniform("vNormalMatrix", mat3<float>::Transpose(mat3<float>::Inverse(modelMatrix)));
			SHADER_MANAGER->GetShader()->SetUniform("fViewPos", ENTITY_MANAGER->GetActiveCamera()->GetPosition());
			ApplyLighting();

			// Draw each mesh
			unsigned int indicesOffset = 0;
			unsigned int meshNum = 0;
			for (auto& mesh : RESOURCE_MANAGER->GetModel(modelRUID)->GetMeshes())
			{
				RESOURCE_MANAGER->GetTexture(meshesTextureRUIDS[meshNum])->Bind();

				glDrawElements(GL_TRIANGLES, mesh.GetNumIndices(), GL_UNSIGNED_INT, (const void*)(indicesOffset * sizeof(ELEMENT_BUFFER_DATA_TYPE)));
				indicesOffset += mesh.GetNumIndices();

				RESOURCE_MANAGER->GetTexture(meshesTextureRUIDS[meshNum])->Unbind();
				meshNum += 1;
			}
			
			// Unbind buffers
			RESOURCE_MANAGER->GetElementBuffer(ebRUID)->UnbindEBO();
			RESOURCE_MANAGER->GetVertexBuffer(vbRUID)->UnbindVAO();
		}
	}

	void RenderManager::ApplyLighting() const
	{
		int lightNum = 0;
		for (auto* pDirLight : ENTITY_MANAGER->GetEntities<Entities::Lights::DirectionalLight>())
		{
			SHADER_MANAGER->GetShader()->SetUniform("fDirLights[" + std::to_string(lightNum) + "].Direction", pDirLight->GetDirection());
			SHADER_MANAGER->GetShader()->SetUniform("fDirLights[" + std::to_string(lightNum) + "].Ambient", pDirLight->GetAmbient());
			SHADER_MANAGER->GetShader()->SetUniform("fDirLights[" + std::to_string(lightNum) + "].Diffuse", pDirLight->GetDiffuse());
			SHADER_MANAGER->GetShader()->SetUniform("fDirLights[" + std::to_string(lightNum) + "].Specular", pDirLight->GetSpecular());
			lightNum += 1;
		}
	}

}