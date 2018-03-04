#pragma once

#include "Manager.h"
#include "..\Entities\GameObject.h"
#include "..\Entities\Lights\PointLight.h"
#include "..\Graphics\Shader.h"

#include <MathsLib\Containers\mat4.h>
#include <glad\glad.h>
#include <vector>

using Maths::Containers::mat4;

namespace Managers {

	class GE_API RenderManager final : public Manager
	{
	public:
		RenderManager();
		static RenderManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		void Draw();
	private:
		void DrawRenderableGameObjects();
		void DrawRenderableLights();
	private:
		void ApplyLighting(Graphics::Shader* const pShader) const;
		void DrawMeshes(Graphics::Shader* const pShader, Components::CModel* const pCModel) const;
	private:
		static RenderManager* m_pInstance;
		// Renderable means the entity has a model associated with it
		std::vector<Entities::GameObject*> m_RenderableGameObjects;
		std::vector<Entities::Lights::PointLight*> m_RenderablePointLights;
	};

}

#define RENDER_MANAGER Managers::RenderManager::Instance()