#pragma once

#include "Buffer.h"

namespace Resources::Buffers {

	class GE_API VertexBuffer final : public Buffer
	{
	public:
		VertexBuffer(unsigned int bufferSize, const std::string& RUID);
		~VertexBuffer();

		void Init() override;
		void LoadData(unsigned int offset, unsigned int size, const void* pData) override;

		void BindVAO();
		void BindVBO();
		void UnbindVAO();
		void UnbindVBO();
	private:
		void SetupVAO();
	private:
		unsigned int m_VertexArrayObject = 0;
	};

}