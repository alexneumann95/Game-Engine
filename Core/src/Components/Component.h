#pragma once

#include "..\Common.h"

namespace Entities { class GameObject; }

namespace Components {

	class GE_API Component
	{
	public:
		Component(Entities::GameObject* const pGameObject); // The game object the component belongs to

		Entities::GameObject* const GetGameObject() const;

		virtual void Init() = 0;
	private:
		Entities::GameObject* m_pGameObject;
	};

}