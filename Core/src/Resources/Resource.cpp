#include "Resource.h"

namespace Resources {

	Resource::Resource(const string& RUID) : m_RUID(RUID)
	{

	}

	const string& Resource::GetRUID() const
	{
		return m_RUID;
	}

}