#pragma once

#include "Entity.h"
#include "..\Managers\EUID.h"

namespace Entities {

	class GE_API GameObject : public Entity
	{
	public:
		GameObject();
		GameObject(const GameObject& other);
		~GameObject();

		virtual GameObject* Clone() const;

		void Start() override { }
		void Update() override { }
	};

}

#define GAME_OBJECT_CLONE_METHOD(className) virtual Entities::GameObject* Clone() const { return new className(*this); }