#include "RVertexBuffer.h"

namespace Resources::Buffers {

	RVertexBuffer::RVertexBuffer(unsigned int bufferSize, const std::string& RUID) : RBuffer(bufferSize, RUID)
	{

	}

	RVertexBuffer::~RVertexBuffer()
	{
		glDeleteVertexArrays(1, &m_VertexArrayObject);
	}

	void RVertexBuffer::Init()
	{
		CreateBuffer();
		SetupVAO();
	}

	void RVertexBuffer::LoadData(unsigned int offset, unsigned int size, const void* pData)
	{
		if ((offset + size) > GetBufferSize())
		{
			LogError("Could not load data into the vertex buffer!");
			return;
		}

		glNamedBufferSubData(GetBufferObject(), offset, size, pData);
	}

	void RVertexBuffer::BindVAO()
	{
		glBindVertexArray(m_VertexArrayObject);
	}

	void RVertexBuffer::BindVBO()
	{
		glBindBuffer(GL_ARRAY_BUFFER, GetBufferObject());
	}

	void RVertexBuffer::UnbindVAO()
	{
		glBindVertexArray(0);
	}

	void RVertexBuffer::UnbindVBO()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void RVertexBuffer::SetupVAO()
	{
		glCreateVertexArrays(1, &m_VertexArrayObject);

		BindVAO();
		BindVBO();

		glVertexAttribPointer(0, 3, GL_FLOAT, false, 12 * sizeof(float), 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, false, 12 * sizeof(float), (const void*)(3 * sizeof(float)));
		glVertexAttribPointer(2, 4, GL_FLOAT, false, 12 * sizeof(float), (const void*)(6 * sizeof(float)));
		glVertexAttribPointer(3, 2, GL_FLOAT, false, 12 * sizeof(float), (const void*)(10 * sizeof(float)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);

		UnbindVBO();
		UnbindVAO();
	}

}