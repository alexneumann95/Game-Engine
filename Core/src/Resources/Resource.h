#pragma once

#include "..\Common.h"

#include <string>

namespace Resources {

	class GE_API Resource
	{
	public:
		Resource(const std::string& RUID);

		const std::string& GetRUID() const;

		virtual void Init() = 0;
	private:
		const std::string m_RUID = "NULL";
	};

}