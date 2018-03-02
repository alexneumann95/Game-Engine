#pragma once

#include "Component.h"
#include "..\Resources\Buffers\RVertexBuffer.h"
#include "..\Resources\Buffers\RElementBuffer.h"

namespace Components {

	class GE_API CRender final : public Component
	{
	public:
		CRender(Entities::GameObject* const pGameObject);

		void Init() override;

		const std::string& GetVertexBufferRUID() const;
		const std::string& GetElementBufferRUID() const;
	private:
		std::string m_VBRUID; // Vertex Buffer RUID
		std::string m_EBRUID; // Element Buffer RUID
	};

}