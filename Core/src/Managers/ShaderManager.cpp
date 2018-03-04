#include "ShaderManager.h"

namespace Managers {

	ShaderManager* ShaderManager::m_pInstance = nullptr;

	ShaderManager::ShaderManager()
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;
	}

	ShaderManager* ShaderManager::Instance()
	{
		return m_pInstance;
	}

	bool ShaderManager::Start()
	{
		std::vector<Graphics::ShaderDesc> modelShaderDescs =
		{
			{ GL_VERTEX_SHADER, "Model.vert" },
			{ GL_FRAGMENT_SHADER, "Model.frag" }
		};
		m_pModelShader = new Graphics::Shader(modelShaderDescs);

		std::vector<Graphics::ShaderDesc> lightShaderDescs =
		{
			{ GL_VERTEX_SHADER, "Light.vert" },
			{ GL_FRAGMENT_SHADER, "Light.frag" }
		};
		m_pLightShader = new Graphics::Shader(lightShaderDescs);

		return true;
	}

	bool ShaderManager::Stop()
	{
		delete m_pModelShader;
		delete m_pLightShader;
		return true;
	}

	void ShaderManager::Update()
	{

	}

	Graphics::Shader* const ShaderManager::GetShader(Graphics::ShaderType type) const
	{
		if (type == Graphics::ShaderType::MODEL)
			return m_pModelShader;
		else if (type == Graphics::ShaderType::LIGHT)
			return m_pLightShader;

		return nullptr;
	}

}