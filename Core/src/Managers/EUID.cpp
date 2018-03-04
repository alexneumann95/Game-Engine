#include "EUID.h"

namespace Managers {

	std::string NextGameObjectEUID()
	{
		static int nextGameObjectNo = 1;
		std::string id = "Entities.GameObjects." + std::to_string(nextGameObjectNo++);
		return id;
	}

	std::string NextCameraEUID()
	{
		static int nextCameraNo = 1;
		std::string id = "Entities.Cameras." + std::to_string(nextCameraNo++);
		return id;
	}

	std::string NextDirectionalLightEUID()
	{
		static int nextLightNo = 1;
		std::string id = "Entities.Light.Directional." + std::to_string(nextLightNo);
		if (nextLightNo < MAX_NUM_DIRECTIONAL_LIGHTS)
			nextLightNo += 1;
		return id;
	}

	std::string NextPointLightEUID()
	{
		static int nextLightNo = 1;
		std::string id = "Entities.Light.Point." + std::to_string(nextLightNo);
		if (nextLightNo < MAX_NUM_POINT_LIGHTS)
			nextLightNo += 1;
		return id;
	}

}