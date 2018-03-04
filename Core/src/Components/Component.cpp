#include "Component.h"
#include "..\Entities\GameObject.h"

namespace Components {

	Component::Component(Entities::Entity* const pEntity, ComponentType type) : m_pEntity(pEntity), m_Type(type)
	{

	}

	Entities::Entity* const Component::GetEntity() const
	{
		return m_pEntity;
	}

	ComponentType Component::GetType() const
	{
		return m_Type;
	}

}