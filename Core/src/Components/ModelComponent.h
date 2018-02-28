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
		// Returns the texture RUID for each mesh in order (e.g. first textureRUID corresponds to first meshes' textureRUID)
		const std::vector<std::string>& GetMeshesTextureRUIDS() const;
	private:
		std::string m_ModelFile = "";
		std::string m_ModelRUID = "";
		std::vector<std::string> m_MeshesTextureRUIDS;
	};

}