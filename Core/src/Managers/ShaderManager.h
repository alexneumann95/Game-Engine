#pragma once

#include "Manager.h"
#include "..\Graphics\Shader.h"
#include "..\Graphics\ShaderType.h"

namespace Managers {

	class GE_API ShaderManager final : public Manager
	{
	public:
		ShaderManager();
		static ShaderManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		Graphics::Shader* const GetShader(Graphics::ShaderType type) const;
	private:
		static ShaderManager* m_pInstance;
		Graphics::Shader* m_pModelShader = nullptr;
		Graphics::Shader* m_pLightShader = nullptr;
	};

}

#define SHADER_MANAGER Managers::ShaderManager::Instance()