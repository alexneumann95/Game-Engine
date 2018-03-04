#include "CRender.h"
#include "..\Managers\ResourceManager.h"
#include "..\Entities\GameObject.h"

namespace Components {

	CRender::CRender(Entities::Entity* const pEntity) : Component(pEntity, ComponentType::RENDER)
	{

	}

	void CRender::Init()
	{
		if (GetEntity()->GetComponent<Components::CModel>() != nullptr)
		{
			auto pModel = RESOURCE_MANAGER->GetModel(GetEntity()->GetComponent<Components::CModel>()->GetModelRUID());

			// Create vertex & index buffers
			unsigned int vbSize = pModel->GetModelVertexByteSize();
			unsigned int ebCount = pModel->GetModelIndicesCount();
			m_VBRUID = RESOURCE_MANAGER->AddVertexBuffer(vbSize);
			m_EBRUID = RESOURCE_MANAGER->AddElementBuffer(ebCount);

			// Load Data into buffers
			auto pVB = RESOURCE_MANAGER->GetVertexBuffer(m_VBRUID);
			auto pEB = RESOURCE_MANAGER->GetElementBuffer(m_EBRUID);
			unsigned int vbOffset = 0; // byte size
			unsigned int ebOffsetCount = 0; // number of indices to offset in the eb by
			ELEMENT_BUFFER_DATA_TYPE indexOffset = 0;
			for (auto& mesh : pModel->GetMeshes())
			{
				pVB->LoadData(vbOffset, mesh.GetVerticesByteSize(), mesh.GetVertices().data());
				vbOffset += mesh.GetVerticesByteSize();

				// Need to offset indices relative to their location in the element buffer
				std::vector<ELEMENT_BUFFER_DATA_TYPE> newIndices;
				for (auto& index : mesh.GetIndices())
					newIndices.push_back(index + indexOffset);
				indexOffset += mesh.GetNumVertices();

				pEB->LoadData(ebOffsetCount, mesh.GetNumIndices(), newIndices.data());
				ebOffsetCount += mesh.GetNumIndices();
			}
		}
	}

	const std::string& CRender::GetVertexBufferRUID() const
	{
		return m_VBRUID;
	}

	const std::string& CRender::GetElementBufferRUID() const
	{
		return m_EBRUID;
	}

}