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
	private:
		std::string m_VBRUID; // Vertex Buffer RUID
		std::string m_EBRUID; // Element Buffer RUID
	};

}