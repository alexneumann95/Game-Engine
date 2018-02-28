#include "Buffer.h"

namespace Resources::Buffers {

	Buffer::Buffer(unsigned int bufferSize, const std::string& RUID) : Resource(RUID), m_Size(bufferSize)
	{

	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_BufferObject);
	}

	unsigned int Buffer::GetBufferSize() const
	{
		return m_Size;
	}

	unsigned int Buffer::GetBufferObject() const
	{
		return m_BufferObject;
	}

	void Buffer::CreateBuffer()
	{
		glCreateBuffers(1, &m_BufferObject);
		glNamedBufferStorage(m_BufferObject, m_Size, nullptr, GL_DYNAMIC_STORAGE_BIT);
	}

}