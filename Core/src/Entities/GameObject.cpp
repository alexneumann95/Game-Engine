#include "GameObject.h"
#include "..\Managers\ResourceManager.h"

namespace Entities {

	GameObject::GameObject() : Entity(Managers::NextGameObjectEUID(), EntityType::GAME_OBJECT)
	{
		
	}

	GameObject::GameObject(const GameObject& other) : Entity(other.GetEUID(), EntityType::GAME_OBJECT)
	{
		AddComponent<Components::CTransform>(); // Every game object has a transform component (when added to the entity manager)
	}

	GameObject::~GameObject()
	{
		for (auto* comp : m_Components)
			delete comp;
	}

	GameObject* GameObject::Clone() const
	{
		return new GameObject(*this);
	}

	void GameObject::InitComponents()
	{
		if (m_ComponentsInitialised)
			return;

		auto InitComponent = [&](Components::Component* const pComponent) {
			if (pComponent != nullptr)
				pComponent->Init();
		};

		InitComponent(GetComponent<Components::CTransform>());
		InitComponent(GetComponent<Components::CModel>());
		InitComponent(GetComponent<Components::CRender>());

		m_ComponentsInitialised = true;
	}

	template <typename Type>
	void GameObject::AddComponent()
	{
		if (GetComponent<Type>() == nullptr)
			m_Components.push_back(new Type(this));
	}

	template <typename Type>
	Type* const GameObject::GetComponent()
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