#pragma once

#include "Component.h"
#include "..\Resources\RModel.h"
#include "..\Resources\RTexture.h"

namespace Components {

	struct MeshTexturesDesc
	{
		int MeshIndex;
		std::string MeshTextureRUID;

		MeshTexturesDesc(int meshIndex, const std::string& meshTextureRUID) : MeshIndex(meshIndex), MeshTextureRUID(meshTextureRUID)
		{

		}
	};

	class GE_API CModel final : public Component
	{
	public:
		CModel(Entities::Entity* const pEntity);

		void Init() override;

		void AddModelFile(const std::string& fileName);

		const std::string& GetModelRUID() const;
		// Gets the mesh texture desc for a particular mesh index of the model
		// If there is no mesh texture desc, nullptr is returned
		const MeshTexturesDesc* const GetMeshTexturesDesc(int meshIndex) const;
	private:
		std::string m_ModelFile = "";
		std::string m_ModelRUID = "";
		std::vector<MeshTexturesDesc> m_MeshTexturesDescs;
	};

}