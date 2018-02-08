#pragma once

#include "Buffer.h"

namespace Resources { namespace Buffers {

	class API ElementBuffer final : public Buffer
	{
	public:
		ElementBuffer(unsigned int bufferSize, const char* const RUID);
		~ElementBuffer();

		void Init() override;
		void LoadData(unsigned int offset, unsigned int size, const void* data) override;

		void BindEBO();
	private:
	};

} }