#include "RBuffer.h"

namespace Resources::Buffers {

	RBuffer::RBuffer(unsigned int bufferSize, const std::string& RUID) : Resource(RUID), m_Size(bufferSize)
	{

	}

	RBuffer::~RBuffer()
	{
		glDeleteBuffers(1, &m_BufferObject);
	}

	unsigned int RBuffer::GetBufferSize() const
	{
		return m_Size;
	}

	unsigned int RBuffer::GetBufferObject() const
	{
		return m_BufferObject;
	}

	void RBuffer::CreateBuffer()
	{
		glCreateBuffers(1, &m_BufferObject);
		glNamedBufferStorage(m_BufferObject, m_Size, nullptr, GL_DYNAMIC_STORAGE_BIT);
	}

}