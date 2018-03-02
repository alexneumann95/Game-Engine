#pragma once

#include "..\Common.h"
#include "ComponentType.h"

namespace Entities { class GameObject; }

namespace Components {

	class GE_API Component
	{
	public:
		Component(Entities::GameObject* const pGameObject, ComponentType type); // The game object the component belongs to

		Entities::GameObject* const GetGameObject() const;
		ComponentType GetType() const;

		virtual void Init() { };
	private:
		Entities::GameObject* m_pGameObject;
		ComponentType m_Type;
	};

}