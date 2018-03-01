#pragma once

#include "..\Common.h"
#include <string>

namespace Managers {

	GE_API std::string NextGameObjectEUID();
	GE_API std::string NextCameraEUID();
	GE_API std::string NextDirectionalLightEUID();

}