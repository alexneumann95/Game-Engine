#include "Model.h"
#include "..\Managers\FileManager.h"

namespace Resources {

	Model::Model(const std::string& file, const std::string& RUID) : Resource(RUID), m_File(file)
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

	void Model::LoadModelData()
	{
		std::ifstream file(Managers::FileManager::Instance()->GetExeDirectory() + "models\\" + m_File);
		if (file.fail())
		{
			LogError("Failed to open model data file: " + m_File);
			return;
		}

		std::string identifier = "";
		std::vector<Maths::vec3> positions;
		std::vector<Maths::vec4> colours;

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
			else if (identifier == "i")
			{
				ELEMENT_BUFFER_DATA_TYPE index;
				for (int i = 0; i < 3; ++i)
				{
					file >> index;
					m_Indices.push_back(index);
				}
			}
			else
				LogError("Unknown identifier read in: " + m_File);

		}

		if (positions.size() != colours.size())
		{
			LogError("The number of positions is not equal to the number of colours for: " + m_File);
			return;
		}

		for (int i = 0; i < positions.size(); ++i)
			m_Vertices.push_back(Graphics::Vertex(positions[i], colours[i]));

		file.close();
	}

}