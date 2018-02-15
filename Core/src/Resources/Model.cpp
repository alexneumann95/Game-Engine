#include "Model.h"
#include "..\Managers\FileManager.h"

namespace Resources {

	Model::Model(const std::string& file, const std::string& RUID) : Resource(RUID), m_ModelFile(file)
	{

	}

	Model::~Model()
	{

	}

	void Model::Init()
	{
		LoadModelData();
	}

	const std::vector<Graphics::Vertex>& Model::GetVertices() const
	{
		return m_Vertices;
	}

	const std::vector<ELEMENT_BUFFER_DATA_TYPE>& Model::GetIndices() const
	{
		return m_Indices;
	}

	unsigned int Model::GetNumVertices() const
	{
		return static_cast<unsigned int>(m_Vertices.size());
	}

	unsigned int Model::GetNumIndices() const
	{
		return static_cast<unsigned int>(m_Indices.size());
	}

	const std::string& const Model::GetTextureFileName() const
	{
		return m_TextureFile;
	}

	void Model::LoadModelData()
	{
		std::ifstream file(FILE_MANAGER->GetExeDirectory() + "models\\" + m_ModelFile);
		if (file.fail())
		{
			LogError("Failed to open model data file: " + m_ModelFile);
			return;
		}

		std::string identifier = "";
		std::vector<Maths::vec3> positions;
		std::vector<Maths::vec4> colours;
		std::vector<Maths::vec2> texCoords;

		while (!file.eof())
		{	
			file >> identifier;

			if (identifier == "v")
			{
				float x, y, z;
				file >> x; file >> y; file >> z;
				positions.push_back(Maths::vec3(x, y, z));
			}
			else if (identifier == "c")
			{
				float x, y, z, w;
				file >> x; file >> y; file >> z; file >> w;
				colours.push_back(Maths::vec4(x, y, z, w));
			}
			else if (identifier == "t")
			{
				float x, y;
				file >> x; file >> y;
				texCoords.push_back(Maths::vec2(x, y));
			}
			else if (identifier == "i")
			{
				ELEMENT_BUFFER_DATA_TYPE index;
				for (int i = 0; i < 3; ++i)
				{
					file >> index;
					m_Indices.push_back(index);
				}
			}
			else if (identifier == "tf")
			{
				file >> m_TextureFile;
			}
			else
				LogError("Unknown identifier read in: " + m_ModelFile);

		}

		if (positions.size() != colours.size() || positions.size() != texCoords.size())
		{
			LogError("Data file is incomplete! (" + m_ModelFile + ")");
			return;
		}

		for (int i = 0; i < positions.size(); ++i)
			m_Vertices.push_back(Graphics::Vertex(positions[i], colours[i], texCoords[i]));

		file.close();
	}

}