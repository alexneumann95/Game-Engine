#include "RElementBuffer.h"

namespace Resources::Buffers {

	RElementBuffer::RElementBuffer(unsigned int count, const std::string& RUID) : RBuffer(count * sizeof(ELEMENT_BUFFER_DATA_TYPE), RUID)
	{

	}

	RElementBuffer::~RElementBuffer()
	{

	}

	void RElementBuffer::Init()
	{
		CreateBuffer();
	}

	void RElementBuffer::LoadData(unsigned int offsetCount, unsigned int count, const void* pData)
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

	void RElementBuffer::BindEBO()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GetBufferObject());
	}

	void RElementBuffer::UnbindEBO()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}