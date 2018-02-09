#pragma once

#include "Buffer.h"

namespace Resources { namespace Buffers {

	class GE_API VertexBuffer final : public Buffer
	{
	public:
		VertexBuffer(unsigned int bufferSize, const string& RUID);
		~VertexBuffer();

		void Init() override;
		void LoadData(unsigned int offset, unsigned int size, const void* data) override;

		void BindVAO();
		void BindVBO();
	private:
		void SetupVAO();
	private:
		unsigned int m_VertexArrayObject = 0;
	};

} }