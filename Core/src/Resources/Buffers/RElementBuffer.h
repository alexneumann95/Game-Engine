#pragma once

#include "RBuffer.h"

#define ELEMENT_BUFFER_DATA_TYPE unsigned int

namespace Resources::Buffers {

	class RElementBuffer final : public RBuffer
	{
	public:
		RElementBuffer(unsigned int count, const std::string& RUID);
		~RElementBuffer();

		void Init() override;
		void LoadData(unsigned int offsetCount, unsigned int count, const void* pData) override;

		void BindEBO();
		void UnbindEBO();
	private:
	};

}