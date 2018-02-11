#pragma once

#include "Manager.h"
#include "..\Graphics\Shader.h"

namespace Managers {

	class GE_API ShaderManager final : public Manager
	{
	public:
		ShaderManager();
		static ShaderManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		Graphics::Shader* const GetShader() const;
	private:
		static ShaderManager* m_pInstance;
		Graphics::Shader* m_pShader = nullptr;
	};

}

#define SHADER_MANAGER Managers::ShaderManager::Instance()