#include "VertexBuffer.h"

namespace Resources { namespace Buffers {

	VertexBuffer::VertexBuffer(unsigned int bufferSize, const std::string& RUID) : Buffer(bufferSize, RUID)
	{

	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteVertexArrays(1, &m_VertexArrayObject);
	}

	void VertexBuffer::Init()
	{
		CreateBuffer();
		SetupVAO();
	}

	void VertexBuffer::LoadData(unsigned int offset, unsigned int size, const void* pData)
	{
		if ((offset + size) > GetBufferSize())
		{
			LogError("Could not load data into the vertex buffer!");
			return;
		}

		glNamedBufferSubData(GetBufferObject(), offset, size, pData);
	}

	void VertexBuffer::BindVAO()
	{
		glBindVertexArray(m_VertexArrayObject);
	}

	void VertexBuffer::BindVBO()
	{
		glBindBuffer(GL_ARRAY_BUFFER, GetBufferObject());
	}

	void VertexBuffer::SetupVAO()
	{
		glCreateVertexArrays(1, &m_VertexArrayObject);

		BindVAO();
		BindVBO();

		glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * 4, 0);
		glEnableVertexAttribArray(0);
	}

} }