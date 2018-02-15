#include "RUID.h"

namespace Managers {

	std::string NextVertexBufferRUID()
	{
		static int nextVertexBufferNo = 1;
		std::string id = "Resources.Buffers.Vertex." + std::to_string(nextVertexBufferNo++);
		return id;
	}

	std::string NextElementBufferRUID()
	{
		static int nextElementBufferNo = 1;
		std::string id = "Resources.Buffers.Element." + std::to_string(nextElementBufferNo++);;
		return id;
	}

	std::string GenModelRUID(const std::string& file)
	{
		return "Resources.Models." + file.substr(0, file.find_last_of('.'));
	}

	std::string GenTextureRUID(const std::string& file)
	{
		return "Resources.Textures." + file.substr(0, file.find_last_of('.'));
	}

}