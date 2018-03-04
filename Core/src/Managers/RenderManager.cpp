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
		m_RenderableGameObjects.clear();
		return true;
	}

	void RenderManager::Update()
	{
		// Clear last frame renderables
		m_RenderableGameObjects.clear();
		m_RenderablePointLights.clear();

		// Store which objects to be rendered
		for (auto* pGameObject : ENTITY_MANAGER->GetEntities<Entities::GameObject>())
		{
			// Check if object has required components to be rendered
			if (pGameObject->GetComponent<Components::CRender>() == nullptr || pGameObject->GetComponent<Components::CModel>() == nullptr) continue;
			// Add renderable to the vector
			m_RenderableGameObjects.push_back(pGameObject);
		}

		for (auto* pPointLight : ENTITY_MANAGER->GetEntities<Entities::Lights::PointLight>())
		{
			// Check if object has required components to be rendered
			if (pPointLight->GetComponent<Components::CRender>() == nullptr || pPointLight->GetComponent<Components::CModel>() == nullptr) continue;
			// Add renderable to the vector
			m_RenderablePointLights.push_back(pPointLight);
		}
	}

	void RenderManager::Draw()
	{
		DrawRenderableGameObjects();
		DrawRenderableLights();
	}

	void RenderManager::DrawRenderableGameObjects()
	{
		auto* pModelShader = SHADER_MANAGER->GetShader(Graphics::ShaderType::MODEL);
		pModelShader->Use();
		// Draw each renderable object
		for (auto* pRenderable : m_RenderableGameObjects)
		{
			// Get Pointers to required components
			auto* pCModel = pRenderable->GetComponent<Components::CModel>();
			auto* pCRender = pRenderable->GetComponent<Components::CRender>();
			auto* pCTransform = pRenderable->GetComponent<Components::CTransform>();

			// Bind buffers
			RESOURCE_MANAGER->GetVertexBuffer(pCRender->GetVertexBufferRUID())->BindVAO();
			RESOURCE_MANAGER->GetElementBuffer(pCRender->GetElementBufferRUID())->BindEBO();

			// Calculate Matrices
			mat4<float> viewMatrix = ENTITY_MANAGER->GetActiveCamera()->GetViewMatrix();
			mat4<float> projMatrix = ENTITY_MANAGER->GetActiveCamera()->GetPerspectiveMatrix();
			mat4<float> modelMatrix = pRenderable->GetComponent<Components::CTransform>()->GetModelMatrix();
			mat4<float> MVPMatrix = projMatrix * viewMatrix * modelMatrix;
			mat3<float> NormalMatrix = mat3<float>::Transpose(mat3<float>::Inverse(modelMatrix));			

			// Set model shader uniforms
			pModelShader->SetUniform("vMVPMatrix", MVPMatrix);
			pModelShader->SetUniform("vModelMatrix", modelMatrix);
			pModelShader->SetUniform("vNormalMatrix", NormalMatrix);
			pModelShader->SetUniform("fViewPos", ENTITY_MANAGER->GetActiveCamera()->GetPosition());

			// Apply Lighting to the scene
			ApplyLighting(pModelShader);

			// Draw each mesh of the Model
			DrawMeshes(pModelShader, pCModel);
			
			// Unbind buffers
			RESOURCE_MANAGER->GetElementBuffer(pCRender->GetElementBufferRUID())->UnbindEBO();
			RESOURCE_MANAGER->GetVertexBuffer(pCRender->GetVertexBufferRUID())->UnbindVAO();
		}
	}

	void RenderManager::DrawRenderableLights()
	{
		auto* pLightShader = SHADER_MANAGER->GetShader(Graphics::ShaderType::LIGHT);
		pLightShader->Use();
		// Draw each renderable light
		for (auto* pRenderable : m_RenderablePointLights)
		{
			// Get Pointers to required components
			auto* pCModel = pRenderable->GetComponent<Components::CModel>();
			auto* pCRender = pRenderable->GetComponent<Components::CRender>();
			auto* pCTransform = pRenderable->GetComponent<Components::CTransform>();

			// Bind buffers
			RESOURCE_MANAGER->GetVertexBuffer(pCRender->GetVertexBufferRUID())->BindVAO();
			RESOURCE_MANAGER->GetElementBuffer(pCRender->GetElementBufferRUID())->BindEBO();

			// Calculate Matrices
			mat4<float> viewMatrix = ENTITY_MANAGER->GetActiveCamera()->GetViewMatrix();
			mat4<float> projMatrix = ENTITY_MANAGER->GetActiveCamera()->GetPerspectiveMatrix();
			mat4<float> modelMatrix = pRenderable->GetComponent<Components::CTransform>()->GetModelMatrix();
			mat4<float> MVPMatrix = projMatrix * viewMatrix * modelMatrix;

			// Set model shader uniforms
			pLightShader->SetUniform("vMVPMatrix", MVPMatrix);

			// Draw meshes
			DrawMeshes(pLightShader, pCModel);

			// Unbind buffers
			RESOURCE_MANAGER->GetElementBuffer(pCRender->GetElementBufferRUID())->UnbindEBO();
			RESOURCE_MANAGER->GetVertexBuffer(pCRender->GetVertexBufferRUID())->UnbindVAO();
		}
	}

	void RenderManager::DrawMeshes(Graphics::Shader* const pShader, Components::CModel* const pCModel) const
	{
		unsigned int indicesOffset = 0;
		auto& meshes = RESOURCE_MANAGER->GetModel(pCModel->GetModelRUID())->GetMeshes();
		for (int i = 0; i < meshes.size(); i++)
		{
			// Retrieve and bind meshes' textures RUID if any
			pShader->SetUniform("fUseTexture0", false); // If no default mesh texture, tell shader to use the meshes' colour values
			Resources::RTexture* pMeshTexture = nullptr;

			auto* meshTexturesDesc = pCModel->GetMeshTexturesDesc(i);
			if (meshTexturesDesc != nullptr)
			{
				pMeshTexture = RESOURCE_MANAGER->GetTexture(meshTexturesDesc->MeshTextureRUID);
				pMeshTexture->Bind();
				pShader->SetUniform("fUseTexture0", true);
			}

			// Draw Mesh
			glDrawElements(GL_TRIANGLES, meshes[i].GetNumIndices(), GL_UNSIGNED_INT, (const void*)(indicesOffset * sizeof(ELEMENT_BUFFER_DATA_TYPE)));
			indicesOffset += meshes[i].GetNumIndices();

			// Unbind textures if any
			if (pMeshTexture != nullptr)
				pMeshTexture->Unbind();

		}
	}

	void RenderManager::ApplyLighting(Graphics::Shader* const pShader) const
	{
		auto& dirLights = ENTITY_MANAGER->GetEntities<Entities::Lights::DirectionalLight>();
		for (int i = 0; i < dirLights.size(); i++)
		{
			pShader->SetUniform("fDirLights[" + std::to_string(i) + "].IsEnabled", true);
			pShader->SetUniform("fDirLights[" + std::to_string(i) + "].Direction", dirLights[i]->GetDirection());
			pShader->SetUniform("fDirLights[" + std::to_string(i) + "].Ambient", dirLights[i]->GetAmbient());
			pShader->SetUniform("fDirLights[" + std::to_string(i) + "].Diffuse", dirLights[i]->GetDiffuse());
			pShader->SetUniform("fDirLights[" + std::to_string(i) + "].Specular", dirLights[i]->GetSpecular());
		}

		auto& pointLights = ENTITY_MANAGER->GetEntities<Entities::Lights::PointLight>();
		for (int i = 0; i < pointLights.size(); i++)
		{
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].IsEnabled", true);
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Position", pointLights[i]->GetComponent<Components::CTransform>()->GetPosition());
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Ambient", pointLights[i]->GetAmbient());
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Diffuse", pointLights[i]->GetDiffuse());
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Specular", pointLights[i]->GetSpecular());
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Constant", pointLights[i]->GetConstant());
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Linear", pointLights[i]->GetLinear());
			pShader->SetUniform("fPointLights[" + std::to_string(i) + "].Quadratic", pointLights[i]->GetQuadratic());
		}
	}

}