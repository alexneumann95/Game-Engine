#pragma once

#include "..\Common.h"
#include "EntityType.h"
#include "..\Components\Component.h"
#include "..\Components\CTransform.h"
#include "..\Components\CModel.h"
#include "..\Components\CRender.h"

#include <list>

namespace Entities {

	class GE_API Entity
	{
	public:
		Entity(const std::string& EUID, EntityType type);
		~Entity();

		virtual Entity* Clone() const = 0;

		const std::string& GetEUID() const;
		EntityType GetType() const;

		virtual void Start() = 0;
		virtual void Update() = 0;

		void InitComponents();
		template <typename Type>
		void AddComponent();
		template <typename Type>
		Type* const GetComponent();
	private:
		const std::string m_EUID = "";
		EntityType m_Type;

		bool m_ComponentsInitialised = false;
		std::list<Components::Component*> m_Components;
	};

}

template GE_API void Entities::Entity::AddComponent<Components::CTransform>();
template GE_API void Entities::Entity::AddComponent<Components::CModel>();
template GE_API void Entities::Entity::AddComponent<Components::CRender>();

template GE_API Components::CTransform* const Entities::Entity::GetComponent<Components::CTransform>();
template GE_API Components::CModel* const Entities::Entity::GetComponent<Components::CModel>();
template GE_API Components::CRender* const Entities::Entity::GetComponent<Components::CRender>();