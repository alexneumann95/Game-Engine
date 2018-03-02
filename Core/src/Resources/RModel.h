#pragma once

#include "Resource.h"
#include "..\Graphics\Mesh.h"

#include <vector>
#include <fstream>

namespace Resources {

	class RModel final : public Resource
	{
	public:
		RModel(const std::string& file, const std::string& RUID);
		~RModel();

		void Init() override;

		const std::vector<Graphics::Mesh>& GetMeshes() const;
		int GetNumMeshes() const;
		unsigned int GetModelVertexByteSize() const;
		unsigned int GetModelIndicesCount() const;
	private:
		void LoadModelData();
	private:
		std::string m_ModelFile;
		std::vector<Graphics::Mesh> m_Meshes;
	};

}