#include "ModelComponent.h"
#include "..\Managers\ResourceManager.h"

namespace Components {

	ModelComponent::ModelComponent(const std::string& file, Entities::GameObject* const pGameObject) : Component(pGameObject), m_ModelFile(file)
	{

	}

	void ModelComponent::Init()
	{
		m_ModelRUID = RESOURCE_MANAGER->AddModel(m_ModelFile);
		m_pModel = RESOURCE_MANAGER->GetModel(m_ModelRUID);
	}

	const std::string& ModelComponent::GetModelRUID() const
	{
		return m_ModelRUID;
	}

	Resources::Model* const ModelComponent::GetModel() const
	{
		return m_pModel;
	}

}