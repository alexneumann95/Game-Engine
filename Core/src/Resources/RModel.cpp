#include "RModel.h"
#include "..\Managers\FileManager.h"

namespace Resources {

	RModel::RModel(const std::string& file, const std::string& RUID) : Resource(RUID), m_ModelFile(file)
	{

	}

	RModel::~RModel()
	{

	}

	void RModel::Init()
	{
		LoadModelData();
	}

	const std::vector<Graphics::Mesh>& RModel::GetMeshes() const
	{
		return m_Meshes;
	}

	int RModel::GetNumMeshes() const
	{
		return static_cast<int>(m_Meshes.size());
	}

	unsigned int RModel::GetModelVertexByteSize() const
	{
		unsigned int size = 0;
		for (auto& mesh : m_Meshes)
			size += mesh.GetNumVertices() * sizeof(Graphics::Vertex);
		return size;
	}

	unsigned int RModel::GetModelIndicesCount() const
	{
		unsigned int count = 0;
		for (auto& mesh : m_Meshes)
			count += mesh.GetNumIndices();
		return count;
	}

	void RModel::LoadModelData()
	{
		std::ifstream file(FILE_MANAGER->GetExeDirectory() + "models\\" + m_ModelFile);
		if (file.fail())
		{
			LogError("Failed to open model data file: " + m_ModelFile);
			return;
		}

		std::string identifier = "";

		while (!file.eof())
		{
			file >> identifier;
			if (identifier == "m")
			{
				std::string name;
				file >> name;
				Graphics::Mesh mesh(name);
				file >> mesh;
				m_Meshes.push_back(mesh);
			}
			else
			{
				LogError("Unknown identifer! Did not find mesh start...");
				return;
			}
		}

		file.close();
	}

}