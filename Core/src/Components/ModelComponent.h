#pragma once

#include "Component.h"
#include "..\Resources\Model.h"
#include "..\Resources\Texture.h"

namespace Components {

	class GE_API ModelComponent final : Component
	{
	public:
		ModelComponent(const std::string& fileName, Entities::GameObject* const pGameObject);

		void Init() override;

		const std::string& GetModelRUID() const;
		const std::string& GetTextureRUID() const;
		Resources::Model* const GetModel() const;
		Resources::Texture* const GetTexture() const;
	private:
		std::string m_ModelFile = "";
		std::string m_ModelRUID = "";
		std::string m_TextureRUID = "";
		Resources::Model* m_pModel = nullptr; // Pointer to the model object in the Resource Manager
		Resources::Texture* m_pTexture = nullptr; // Pointer to the texture in the Resource Manager
	};

}