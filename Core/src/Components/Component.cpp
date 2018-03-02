#include "Component.h"

namespace Components {

	Component::Component(Entities::GameObject* const pGameObject, ComponentType type) : m_pGameObject(pGameObject), m_Type(type)
	{

	}

	Entities::GameObject* const Component::GetGameObject() const
	{
		return m_pGameObject;
	}

	ComponentType Component::GetType() const
	{
		return m_Type;
	}

}