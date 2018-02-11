#pragma once

#include "Entity.h"
#include "..\Managers\EUID.h"
#include "..\Components\ModelComponent.h"
#include "..\Components\RenderComponent.h"

using namespace Components;

namespace Entities {

	class GE_API GameObject : public Entity
	{
	public:
		GameObject(const std::string& EUID = Managers::NextGameObjectEUID());
		~GameObject();

		virtual GameObject* Clone() const;

		void InitComponents();
		void Start() override { }
		void Update() override { }

		void AddModelComp(const std::string& modelFile);
		void AddRenderComp();

		ModelComponent* const GetModelComp() const;
		RenderComponent* const GetRenderComp() const;
	private:
		ModelComponent* m_pModelComp = nullptr;
		RenderComponent* m_pRenderComp = nullptr;
	};

}

#define GAME_OBJECT_CLONE_METHOD(className) virtual Entities::GameObject* Clone() const { return new className(*this); }