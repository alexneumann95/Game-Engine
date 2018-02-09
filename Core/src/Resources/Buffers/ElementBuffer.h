#pragma once

#include "Buffer.h"

namespace Resources { namespace Buffers {

	class GE_API ElementBuffer final : public Buffer
	{
	public:
		ElementBuffer(unsigned int bufferSize, const string& RUID);
		~ElementBuffer();

		void Init() override;
		void LoadData(unsigned int offset, unsigned int size, const void* data) override;

		void BindEBO();
	private:
	};

} }