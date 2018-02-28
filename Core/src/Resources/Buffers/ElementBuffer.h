#pragma once

#include "Buffer.h"

#define ELEMENT_BUFFER_DATA_TYPE unsigned int

namespace Resources::Buffers {

	class GE_API ElementBuffer final : public Buffer
	{
	public:
		ElementBuffer(unsigned int count, const std::string& RUID);
		~ElementBuffer();

		void Init() override;
		void LoadData(unsigned int offsetCount, unsigned int count, const void* pData) override;

		void BindEBO();
		void UnbindEBO();
	private:
	};

}