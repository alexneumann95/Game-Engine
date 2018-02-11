#include "Entity.h"

namespace Entities {

	Entity::Entity(const std::string& EUID) : m_EUID(EUID)
	{

	}

	const std::string& Entity::GetEUID() const
	{
		return m_EUID;
	}

}