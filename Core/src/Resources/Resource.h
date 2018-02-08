#pragma once

#include "..\Common.h"

namespace Resources {

	class API Resource
	{
	public:
		Resource(const char* const RUID);

		const char* const GetRUID() const;

		virtual void Init() = 0;
	private:
		const char* const m_RUID = "NULL";
	};

}