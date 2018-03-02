#pragma once

#include "RBuffer.h"

namespace Resources::Buffers {

	class RVertexBuffer final : public RBuffer
	{
	public:
		RVertexBuffer(unsigned int bufferSize, const std::string& RUID);
		~RVertexBuffer();

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