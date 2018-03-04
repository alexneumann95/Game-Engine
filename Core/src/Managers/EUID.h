#pragma once

#include "..\Common.h"
#include <string>

#define MAX_NUM_DIRECTIONAL_LIGHTS 4
#define MAX_NUM_POINT_LIGHTS 10

namespace Managers {

	GE_API std::string NextGameObjectEUID();
	GE_API std::string NextCameraEUID();
	GE_API std::string NextDirectionalLightEUID();
	GE_API std::string NextPointLightEUID();

}