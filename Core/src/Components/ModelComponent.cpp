#include "ModelComponent.h"
#include "..\Managers\ResourceManager.h"

namespace Components {

	ModelComponent::ModelComponent(const std::string& file, Entities::GameObject* const pGameObject) : Component(pGameObject), m_ModelFile(file)
	{

	}

	void ModelComponent::Init()
	{
		m_ModelRUID = RESOURCE_MANAGER->AddModel(m_ModelFile);

		// Load textures into the RM
		for (auto& mesh : RESOURCE_MANAGER->GetModel(m_ModelRUID)->GetMeshes())
			m_MeshesTextureRUIDS.push_back(RESOURCE_MANAGER->AddTexture(mesh.GetTextureFileName()));
	}

	const std::string& ModelComponent::GetModelRUID() const
	{
		return m_ModelRUID;
	}

	const std::vector<std::string>& ModelComponent::GetMeshesTextureRUIDS() const
	{
		return m_MeshesTextureRUIDS;
	}

}