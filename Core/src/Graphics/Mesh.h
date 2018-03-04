#pragma once

#include "..\Common.h"
#include "Vertex.h"
#include "..\Resources\Buffers\RElementBuffer.h"

#include <vector>
#include <fstream>

namespace Graphics {

	class GE_API Mesh final
	{
	public:
		Mesh(const std::string& name);
		Mesh(const std::string& name, const std::vector<Vertex>& vertices, const std::vector<ELEMENT_BUFFER_DATA_TYPE>& indices);

		const std::string& GetName() const;
		const std::vector<Vertex>& GetVertices() const;
		const std::vector<ELEMENT_BUFFER_DATA_TYPE>& GetIndices() const;
		const std::string& GetMeshTextureFileName() const;
		int GetNumVertices() const;
		int GetNumIndices() const;
		unsigned int GetVerticesByteSize() const;

		friend std::ifstream& operator >> (std::ifstream& is, Mesh& mesh);
	private:
		std::string m_Name;
		std::vector<Vertex> m_Vertices;
		std::vector<ELEMENT_BUFFER_DATA_TYPE> m_Indices;
		std::string m_MeshTextureFileName;
	};

}