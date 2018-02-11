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
		std::vector<Graphics::ShaderDesc> descs =
		{
			{ GL_VERTEX_SHADER, "Basic.vert" },
			{ GL_FRAGMENT_SHADER, "Basic.frag" }
		};
		m_pShader = new Graphics::Shader(descs);

		return true;
	}

	bool ShaderManager::Stop()
	{
		delete m_pShader;
		return true;
	}

	void ShaderManager::Update()
	{

	}

	Graphics::Shader* const ShaderManager::GetShader() const
	{
		return m_pShader;
	}

}