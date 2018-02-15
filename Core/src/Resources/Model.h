#pragma once

#include "Resource.h"
#include "..\Graphics\Vertex.h"
#include "Buffers\ElementBuffer.h"

#include <vector>
#include <fstream>

namespace Resources {

	class GE_API Model final : public Resource
	{
	public:
		Model(const std::string& file, const std::string& RUID);
		~Model();

		void Init() override;

		const std::vector<Graphics::Vertex>& GetVertices() const;
		const std::vector<ELEMENT_BUFFER_DATA_TYPE>& GetIndices() const;
		unsigned int GetNumVertices() const;
		unsigned int GetNumIndices() const;
		const std::string& GetTextureFileName() const;
	private:
		void LoadModelData();
	private:
		std::string m_ModelFile;
		std::string m_TextureFile;
		std::vector<Graphics::Vertex> m_Vertices;
		std::vector<ELEMENT_BUFFER_DATA_TYPE> m_Indices;
	};

}