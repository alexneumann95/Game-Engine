#pragma once

#include "Component.h"
#include "..\Resources\Model.h"

namespace Components {

	class GE_API ModelComponent final : Component
	{
	public:
		ModelComponent(const std::string& fileName, Entities::GameObject* const pGameObject);

		void Init() override;

		const std::string& GetModelRUID() const;
		Resources::Model* const GetModel() const;
	private:
		std::string m_ModelFile = "";
		std::string m_ModelRUID = "";
		Resources::Model* m_pModel = nullptr; // Pointer to the model object in the Resource Manager
	};

}