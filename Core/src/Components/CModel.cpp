#include "CModel.h"
#include "..\Managers\ResourceManager.h"

namespace Components {

	CModel::CModel(Entities::GameObject* const pGameObject) : Component(pGameObject, ComponentType::MODEL)
	{

	}

	void CModel::Init()
	{
		m_ModelRUID = RESOURCE_MANAGER->AddModel(m_ModelFile);

		// Load textures into the RM
		for (auto& mesh : RESOURCE_MANAGER->GetModel(m_ModelRUID)->GetMeshes())
			m_MeshesTextureRUIDS.push_back(RESOURCE_MANAGER->AddTexture(mesh.GetTextureFileName()));
	}

	void CModel::AddModelFile(const std::string& fileName)
	{
		m_ModelFile = fileName;
	}

	const std::string& CModel::GetModelRUID() const
	{
		return m_ModelRUID;
	}

	const std::vector<std::string>& CModel::GetMeshesTextureRUIDS() const
	{
		return m_MeshesTextureRUIDS;
	}

}