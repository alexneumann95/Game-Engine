#pragma once

#include "Entity.h"
#include "..\Managers\EUID.h"
#include "..\Components\Component.h"
#include "..\Components\CTransform.h"
#include "..\Components\CModel.h"
#include "..\Components\CRender.h"

#include <list>

namespace Entities {

	class GE_API GameObject : public Entity
	{
	public:
		GameObject();
		GameObject(const GameObject& other);
		~GameObject();

		virtual GameObject* Clone() const;

		void InitComponents();
		void Start() override { }
		void Update() override { }

		template <typename Type>
		void AddComponent();

		template <typename Type>
		Type* const GetComponent();
	private:
		bool m_ComponentsInitialised = false;
		std::list<Components::Component*> m_Components;
	};

}

#define GAME_OBJECT_CLONE_METHOD(className) virtual Entities::GameObject* Clone() const { return new className(*this); }

template GE_API void Entities::GameObject::AddComponent<Components::CTransform>();
template GE_API void Entities::GameObject::AddComponent<Components::CModel>();
template GE_API void Entities::GameObject::AddComponent<Components::CRender>();

template GE_API Components::CTransform* const Entities::GameObject::GetComponent<Components::CTransform>();
template GE_API Components::CModel* const Entities::GameObject::GetComponent<Components::CModel>();
template GE_API Components::CRender* const Entities::GameObject::GetComponent<Components::CRender>();