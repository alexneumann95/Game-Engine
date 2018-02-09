#include "ElementBuffer.h"

namespace Resources { namespace Buffers {

	ElementBuffer::ElementBuffer(unsigned int bufferSize, const string& RUID) : Buffer(bufferSize, RUID)
	{

	}

	ElementBuffer::~ElementBuffer()
	{

	}

	void ElementBuffer::Init()
	{
		CreateBuffer();
	}

	void ElementBuffer::LoadData(unsigned int offset, unsigned int size, const void* data) 
	{
		if ((offset + size) > GetBufferSize())
		{
			LogError("Could not load data into the element buffer!");
			return;
		}

		glNamedBufferSubData(GetBufferObject(), offset, size, data);
	}

	void ElementBuffer::BindEBO()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GetBufferObject());
	}

} }