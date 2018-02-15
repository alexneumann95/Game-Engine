#include "ElementBuffer.h"

namespace Resources { namespace Buffers {

	ElementBuffer::ElementBuffer(unsigned int count, const std::string& RUID) : Buffer(count * sizeof(ELEMENT_BUFFER_DATA_TYPE), RUID)
	{

	}

	ElementBuffer::~ElementBuffer()
	{

	}

	void ElementBuffer::Init()
	{
		CreateBuffer();
	}

	void ElementBuffer::LoadData(unsigned int offsetCount, unsigned int count, const void* pData)
	{
		unsigned int offset = offsetCount * sizeof(ELEMENT_BUFFER_DATA_TYPE);
		unsigned int size = count * sizeof(ELEMENT_BUFFER_DATA_TYPE);

		if ((offset + size) > GetBufferSize())
		{
			LogError("Could not load data into the element buffer!");
			return;
		}

		glNamedBufferSubData(GetBufferObject(), offset, size, pData);
	}

	void ElementBuffer::BindEBO()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GetBufferObject());
	}

	void ElementBuffer::UnbindEBO()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }