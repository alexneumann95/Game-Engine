#include "CModel.h"
#include "..\Managers\ResourceManager.h"

namespace Components {

	CModel::CModel(Entities::Entity* const pEntity) : Component(pEntity, ComponentType::MODEL)
	{

	}

	void CModel::Init()
	{
		m_ModelRUID = RESOURCE_MANAGER->AddModel(m_ModelFile);

		// Load textures into the RM (if model has any)
		int meshIndex = 0;
		for (auto& mesh : RESOURCE_MANAGER->GetModel(m_ModelRUID)->GetMeshes())
		{
			if (mesh.GetMeshTextureFileName() != "")
				m_MeshTexturesDescs.emplace_back(meshIndex, RESOURCE_MANAGER->AddTexture(mesh.GetMeshTextureFileName()));

			meshIndex += 1;
		}
	}

	void CModel::AddModelFile(const std::string& fileName)
	{
		m_ModelFile = fileName;
	}

	const std::string& CModel::GetModelRUID() const
	{
		return m_ModelRUID;
	}

	const MeshTexturesDesc* const CModel::GetMeshTexturesDesc(int meshIndex) const
	{
		for (auto& meshTextureDesc : m_MeshTexturesDescs)
		{
			if (meshTextureDesc.MeshIndex == meshIndex)
				return &meshTextureDesc;
		}

		return nullptr;
	}

}