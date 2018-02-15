#pragma once

#include "Resource.h"

#include <stb\stb_image.h>

namespace Resources {

	class GE_API Texture final : public Resource
	{
	public:
		Texture(const std::string& file, const std::string& RUID);
		~Texture();

		void Init() override;

		void Bind(GLenum textureSlot = GL_TEXTURE0);
		void Unbind();
	private:
		std::string m_File;
		unsigned int m_Texture = 0;
		int m_Width = 0;
		int m_Height = 0;
	};

}