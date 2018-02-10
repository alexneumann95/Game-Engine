#include "Resource.h"

namespace Resources {

	Resource::Resource(const std::string& RUID) : m_RUID(RUID)
	{

	}

	const std::string& Resource::GetRUID() const
	{
		return m_RUID;
	}

}