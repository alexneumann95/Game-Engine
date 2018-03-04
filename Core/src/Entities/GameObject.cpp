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

	}

	GameObject* GameObject::Clone() const
	{
		return new GameObject(*this);
	}

}