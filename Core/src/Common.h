#pragma once

#include "API.h"

#include <iostream>

#define LogError(msg)																								\
{																													\
	std::cout << "ERROR: " << msg << "\n\tOccured in: " << __FUNCTION__ << " at line number: + " << __LINE__		\
				<< "\n\tFile: " << __FILE__ << std::endl;															\
}