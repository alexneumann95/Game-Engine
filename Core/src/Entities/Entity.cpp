#include "Entity.h"
#include "EntitiesComponents.h"

namespace Entities {

	Entity::Entity(const std::string& EUID, EntityType type) : m_EUID(EUID), m_Type(type)
	{

	}

	Entity::~Entity()
	{
		for (auto* comp : m_Components)
			delete comp;
	}

	const std::string& Entity::GetEUID() const
	{
		return m_EUID;
	}

	EntityType Entity::GetType() const
	{
		return m_Type;	
	}

	void Entity::InitComponents()
	{
		if (m_ComponentsInitialised)
			return;

		auto InitComponent = [](Components::Component* const pComponent) {
			if (pComponent != nullptr)
				pComponent->Init();
		};

		InitComponent(GetComponent<Components::CTransform>());
		InitComponent(GetComponent<Components::CModel>());
		InitComponent(GetComponent<Components::CRender>());

		m_ComponentsInitialised = true;
	}

	template <typename Type>
	void Entity::AddComponent()
	{
		if (GetComponent<Type>() != nullptr)
			return;

		// Create a component class of type "Type" to find out the components enum type
		auto pComponent = dynamic_cast<Components::Component*>(&Type(this));

		// Add component if it is allowed
		std::vector<Components::ComponentType> allowedComponents;
		switch (m_Type)
		{
		case EntityType::GAME_OBJECT:
			allowedComponents = GAME_OBJECT_ALLOWED_COMPONENTS;
			break;
		case EntityType::POINT_LIGHT:
			allowedComponents = POINT_LIGHT_ALLOWED_COMPONENTS;
			break;
		}

		for (auto& type : allowedComponents)
			if (pComponent->GetType() == type)
				m_Components.push_back(new Type(this));
	}

	template <typename Type>
	Type* const Entity::GetComponent()
	{
		Type* pResult = nullptr;
		// Create a component class of type "Type" to find out the components enum type
		auto pComponent = dynamic_cast<Components::Component*>(&Type(this));

		for (auto* comp : m_Components)
		{
			if (comp->GetType() == pComponent->GetType())
				pResult = dynamic_cast<Type* const>(comp);
		}

		return pResult;
	}

}