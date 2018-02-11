#pragma once

#include "Component.h"
#include "..\Resources\Buffers\VertexBuffer.h"
#include "..\Resources\Buffers\ElementBuffer.h"

namespace Components {

	class GE_API RenderComponent final : public Component
	{
	public:
		RenderComponent(Entities::GameObject* const pGameObject);

		void Init() override;

		const std::string& GetVertexBufferRUID() const;
		const std::string& GetElementBufferRUID() const;
		Resources::Buffers::VertexBuffer* const GetVertexBuffer() const;
		Resources::Buffers::ElementBuffer* const GetElementBuffer() const;
	private:
		std::string m_VBRUID; // Vertex Buffer RUID
		std::string m_EBRUID; // Element Buffer RUID
		Resources::Buffers::VertexBuffer* m_pVertexBuffer = nullptr; // Pointer to the Vertex Buffer in the Resource Manager
		Resources::Buffers::ElementBuffer* m_pElementBuffer = nullptr; // Pointer to the Element Buffer in the Resource Manager
	};

}