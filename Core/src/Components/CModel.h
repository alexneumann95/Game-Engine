#pragma once

#include "Component.h"
#include "..\Resources\RModel.h"
#include "..\Resources\RTexture.h"

namespace Components {

	class GE_API CModel final : public Component
	{
	public:
		CModel(Entities::GameObject* const pGameObject);

		void Init() override;

		void AddModelFile(const std::string& fileName);

		const std::string& GetModelRUID() const;
		// Returns the texture RUID for each mesh in order (e.g. first textureRUID corresponds to first meshes' textureRUID)
		const std::vector<std::string>& GetMeshesTextureRUIDS() const;
	private:
		std::string m_ModelFile = "";
		std::string m_ModelRUID = "";
		std::vector<std::string> m_MeshesTextureRUIDS;
	};

}