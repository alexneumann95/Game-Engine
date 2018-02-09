#pragma once

#include "..\Common.h"

#include <string>
using std::string;

namespace Resources {

	class GE_API Resource
	{
	public:
		Resource(const string& RUID);

		const string& GetRUID() const;

		virtual void Init() = 0;
	private:
		const string m_RUID = "NULL";
	};

}