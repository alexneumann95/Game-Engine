#pragma once

#include "..\Common.h"
#include <string>

namespace Managers {

	GE_API std::string NextVertexBufferRUID();
	GE_API std::string NextElementBufferRUID();
	GE_API std::string GenModelRUID(const std::string& file);
	GE_API std::string GenTextureRUID(const std::string& file);

}