#include "Resource.h"

namespace Resources {

	Resource::Resource(const char* const RUID) : m_RUID(RUID)
	{

	}

	const char* const Resource::GetRUID() const
	{
		return m_RUID;
	}

}