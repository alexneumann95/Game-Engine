#include "RenderComponent.h"
#include "..\Managers\ResourceManager.h"
#include "..\Entities\GameObject.h"

namespace Components {

	RenderComponent::RenderComponent(Entities::GameObject* const pGameObject) : Component(pGameObject)
	{

	}

	void RenderComponent::Init()
	{
		if (GetGameObject()->GetModelComp() != nullptr)
		{
			auto pModel = GetGameObject()->GetModelComp()->GetModel();

			unsigned int vbSize = pModel->GetNumVertices() * sizeof(Graphics::Vertex);
			unsigned int ebCount = pModel->GetNumIndices();
			m_VBRUID = RESOURCE_MANAGER->AddVertexBuffer(vbSize);
			m_EBRUID = RESOURCE_MANAGER->AddElementBuffer(ebCount);

			m_pVertexBuffer = RESOURCE_MANAGER->GetVertexBuffer(m_VBRUID);
			m_pElementBuffer = RESOURCE_MANAGER->GetElementBuffer(m_EBRUID);

			m_pVertexBuffer->LoadData(0, vbSize, pModel->GetVertices().data());
			m_pElementBuffer->LoadData(0, ebCount, pModel->GetIndices().data());
		}
	}

	const std::string& RenderComponent::GetVertexBufferRUID() const
	{
		return m_VBRUID;
	}

	const std::string& RenderComponent::GetElementBufferRUID() const
	{
		return m_EBRUID;
	}

	Resources::Buffers::VertexBuffer* const RenderComponent::GetVertexBuffer() const
	{
		return m_pVertexBuffer;
	}

	Resources::Buffers::ElementBuffer* const RenderComponent::GetElementBuffer() const
	{
		return m_pElementBuffer;
	}

}