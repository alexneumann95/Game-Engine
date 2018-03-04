#pragma once

#include "..\Common.h"
#include "ComponentType.h"

namespace Entities { class Entity; class GameObject; }

namespace Components {

	class GE_API Component
	{
	public:
		Component(Entities::Entity* const pEntity, ComponentType type); // The game object the component belongs to

		// Returns a pointer to the entity it belongs to
		Entities::Entity* const GetEntity() const;

		ComponentType GetType() const;

		virtual void Init() { };
	private:
		Entities::Entity* m_pEntity;
		ComponentType m_Type;
	};

}