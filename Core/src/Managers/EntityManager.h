#pragma once

#include "Manager.h"
#include "..\Entities\GameObject.h"
#include "..\Entities\Camera.h"

#include <map>

using namespace Entities;

typedef std::map<std::string, GameObject*> GameObjectsMap;
typedef std::map<std::string, Camera*> CamerasMap;

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

		void SetActiveCamera(const std::string& EUID);
		Camera* const GetActiveCamera() const;

		const std::string& AddGameObject(const GameObject& object);
		const std::string& AddCamera(const Camera& cam);

		bool CheckGameObjectExists(const std::string& EUID);
		bool CheckCameraExists(const std::string& EUID);

		bool DestroyGameObject(const std::string& EUID);
		bool DestroyCamera(const std::string& EUID);
	private:
		static EntityManager* m_pInstance;
		GameObjectsMap m_GameObjects;
		CamerasMap m_Cameras;
		std::string m_ActiveCameraEUID = "";
	};

}

#define ENTITY_MANAGER Managers::EntityManager::Instance()