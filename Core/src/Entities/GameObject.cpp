#include "GameObject.h"
#include "..\Managers\ResourceManager.h"

namespace Entities {

	GameObject::GameObject(const std::string& EUID) : Entity(EUID)
	{

	}

	GameObject::~GameObject()
	{
		delete m_pModelComp;
		delete m_pRenderComp;
	}

	GameObject* GameObject::Clone() const
	{
		return new GameObject(*this);
	}

	void GameObject::InitComponents()
	{
		if (m_pModelComp != nullptr)
			m_pModelComp->Init();
		if (m_pRenderComp != nullptr)
			m_pRenderComp->Init();
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

	ModelComponent* const GameObject::GetModelComp() const
	{
		return m_pModelComp;
	}

	RenderComponent* const GameObject::GetRenderComp() const
	{
		return m_pRenderComp;
	}


}