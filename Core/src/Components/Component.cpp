#include "Component.h"

namespace Components {

	Component::Component(Entities::GameObject* const pGameObject) : m_pGameObject(pGameObject)
	{

	}

	Entities::GameObject* const Component::GetGameObject() const
	{
		return m_pGameObject;
	}

}