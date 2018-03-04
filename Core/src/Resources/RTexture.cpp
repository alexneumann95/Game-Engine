#include "RTexture.h"
#include "..\Managers\FileManager.h"

namespace Resources {

	RTexture::RTexture(const std::string& file, const std::string& RUID) : Resource(RUID), m_File(file)
	{

	}

	RTexture::~RTexture()
	{
		glDeleteTextures(1, &m_Texture);
	}

	void RTexture::Init()
	{
		glGenTextures(1, &m_Texture);
		Bind();
		// Set the texture wrapping & filtering properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// Load & generate the texture
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load((FILE_MANAGER->GetExeDirectory() + "textures\\" + m_File).c_str(), &m_Width, &m_Height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			LogError("Failed to load texture: " + m_File);

		stbi_image_free(data);
		Unbind();
	}

	void RTexture::Bind(GLenum textureSlot)
	{
		glActiveTexture(textureSlot);
		glBindTexture(GL_TEXTURE_2D, m_Texture);
	}

	void RTexture::Unbind(GLenum textureSlot)
	{
		glActiveTexture(textureSlot);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}