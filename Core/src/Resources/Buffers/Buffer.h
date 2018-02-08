#pragma once

#include "..\Resource.h"

#include <glad\glad.h>

namespace Resources { namespace Buffers {

	class API Buffer : public Resource
	{
	public:
		Buffer(unsigned int bufferSize, const char* const RUID);
		~Buffer();

		virtual void LoadData(unsigned int offset, unsigned int size, const void* data) = 0;

		unsigned int GetBufferSize() const;
		unsigned int GetBufferObject() const;
	protected:
		void CreateBuffer();
	private:
		unsigned int m_BufferObject = 0; // The data buffer (E.G. storing vertex data)
		unsigned int m_Size = 0;
	};

} }