#pragma once

#include "Resource.h"

#include <stb\stb_image.h>

namespace Resources {

	class RTexture final : public Resource
	{
	public:
		RTexture(const std::string& file, const std::string& RUID);
		~RTexture();

		void Init() override;

		void Bind(GLenum textureSlot = GL_TEXTURE0);
		void Unbind(GLenum textureSlot = GL_TEXTURE0);
	private:
		std::string m_File;
		unsigned int m_Texture = 0;
		int m_Width = 0;
		int m_Height = 0;
	};

}