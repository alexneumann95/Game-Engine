#include "Entity.h"

namespace Entities {

	Entity::Entity(const std::string& EUID, EntityType type) : m_EUID(EUID), m_Type(type)
	{

	}

	const std::string& Entity::GetEUID() const
	{
		return m_EUID;
	}

	EntityType Entity::GetType() const
	{
		return m_Type;	
	}

}