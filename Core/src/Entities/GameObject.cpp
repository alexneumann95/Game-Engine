#include "GameObject.h"
#include "..\Managers\ResourceManager.h"

namespace Entities {

	GameObject::GameObject(const std::string& EUID) : Entity(EUID, EntityType::GAME_OBJECT)
	{

	}

	GameObject::GameObject(const GameObject& other) : Entity(other.GetEUID(), EntityType::GAME_OBJECT)
	{
		m_pTransformComp = new TransformComponent(this); // Every game object has a transform component (when added to the entity manager)
	}

	GameObject::~GameObject()
	{
		delete m_pTransformComp;
		delete m_pModelComp;
		delete m_pRenderComp;
	}

	GameObject* GameObject::Clone() const
	{
		return new GameObject(*this);
	}

	void GameObject::InitComponents()
	{
		if (m_ComponentsInitialised)
			return;

		m_pTransformComp->Init();

		if (m_pModelComp != nullptr)
			m_pModelComp->Init();
		if (m_pRenderComp != nullptr)
			m_pRenderComp->Init();

		m_ComponentsInitialised = true;
	}

	void GameObject::AddModelComp(const std::string& modelFile)
	{
		if (m_pModelComp == nullptr)
			m_pModelComp = new ModelComponent(modelFile, this);
	}

	void GameObject::AddRenderComp()
	{
		if (m_pRenderComp == nullptr)
			m_pRenderComp = new RenderComponent(this);
	}

	TransformComponent* const GameObject::GetTransformComp() const
	{
		return m_pTransformComp;
	}

	ModelComponent* const GameObject::GetModelComp() const
	{
		return m_pModelComp;
	}

	RenderComponent* const GameObject::GetRenderComp() const
	{
		return m_pRenderComp;
	}


}