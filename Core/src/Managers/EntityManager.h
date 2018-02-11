#pragma once

#include "Manager.h"
#include "..\Entities\GameObject.h"

#include <map>

using namespace Entities;

typedef std::map<std::string, GameObject*> GameObjectsMap;

namespace Managers {

	class GE_API EntityManager final : public Manager
	{
	public:
		EntityManager();
		static EntityManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		const GameObjectsMap& GetGameObjects() const;

		const std::string& AddGameObject(const GameObject& object);

		bool CheckGameObjectExists(const std::string& EUID);

		bool DestroyGameObject(const std::string& EUID);
	private:
		static EntityManager* m_pInstance;
		GameObjectsMap m_GameObjects;
	};

}

#define ENTITY_MANAGER Managers::EntityManager::Instance()