#include "Mesh.h"

namespace Graphics {

	Mesh::Mesh(const std::string& name) : m_Name(name)
	{

	}

	Mesh::Mesh(const std::string& name, const std::vector<Vertex>& vertices, const std::vector<ELEMENT_BUFFER_DATA_TYPE>& indices) : m_Name(name), m_Vertices(vertices), m_Indices(indices)
	{

	}

	const std::string& Mesh::GetName() const
	{
		return m_Name;
	}

	const std::vector<Vertex>& Mesh::GetVertices() const
	{
		return m_Vertices;
	}

	const std::vector<ELEMENT_BUFFER_DATA_TYPE>& Mesh::GetIndices() const
	{
		return m_Indices;
	}

	const std::string& Mesh::GetMeshTextureFileName() const
	{
		return m_MeshTextureFileName;
	}

	int Mesh::GetNumVertices() const
	{
		return static_cast<int>(m_Vertices.size());
	}

	int Mesh::GetNumIndices() const
	{
		return static_cast<int>(m_Indices.size());
	}

	unsigned int Mesh::GetVerticesByteSize() const
	{
		return GetNumVertices() * sizeof(Vertex);
	}

	std::ifstream& operator >> (std::ifstream& is, Mesh& mesh)
	{
		std::vector<vec2<float>> texCoords;
		std::vector<vec3<float>> positions;
		std::vector<vec3<float>> normals;
		std::vector<vec4<float>> colours;
		std::vector<ELEMENT_BUFFER_DATA_TYPE> indices;

		std::string identifier;
		while (is >> identifier)
		{
			if (identifier == "v")
			{
				float x, y, z;
				is >> x; is >> y; is >> z;
				positions.emplace_back(x, y, z);
			}
			else if (identifier == "n")
			{
				float x, y, z;
				is >> x; is >> y; is >> z;
				normals.emplace_back(x, y, z);
			}
			else if (identifier == "c")
			{
				float x, y, z, w;
				is >> x; is >> y; is >> z; is >> w;
				colours.emplace_back(x, y, z, w);
			}
			else if (identifier == "t")
			{
				float x, y;
				is >> x; is >> y;
				texCoords.emplace_back(x, y);
			}
			else if (identifier == "i")
			{
				ELEMENT_BUFFER_DATA_TYPE index;
				for (int i = 0; i < 3; i++)
				{
					is >> index;
					indices.push_back(index);
				}
			}
			else if (identifier == "mtf")
			{
				is >> mesh.m_MeshTextureFileName;
			}
			else if (identifier == "end")
				break;
		}

		if (texCoords.size() == positions.size() && positions.size() == normals.size() && normals.size() == colours.size() && indices.size() != 0)
		{
			for (int i = 0; i < positions.size(); i++)
				mesh.m_Vertices.push_back(Graphics::Vertex(positions[i], normals[i], colours[i], texCoords[i]));
			for (int i = 0; i < indices.size(); i++)
				mesh.m_Indices.push_back(indices[i]);
		}
		else
			LogError("Mesh data is not complete for " + mesh.m_Name + "!");

		return is;
	}

}