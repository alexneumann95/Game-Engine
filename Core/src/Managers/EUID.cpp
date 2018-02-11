#include "EUID.h"

namespace Managers {

	std::string NextGameObjectEUID()
	{
		static int nextGameObjectNo = 1;
		std::string id = "Entities.GameObjects." + std::to_string(nextGameObjectNo++);
		return id;
	}

}