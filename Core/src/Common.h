#pragma once
#pragma warning (disable: 4251)

#include "API.h"
#include "Utilities\Errors.h"

#include <iostream>
#include <assert.h>

#define LogError(msg)																								\
{																													\
	std::cout << "ERROR: " << msg << "\n\tOccured in: " << __FUNCTION__ << " at line number: " << __LINE__			\
				<< "\n\tFile: " << __FILE__ << std::endl;															\
}