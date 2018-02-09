#pragma once

#include "..\Common.h"

namespace Managers {

	class GE_API Manager
	{
	public:
		virtual bool Start() = 0;
		virtual bool Stop() = 0;
		virtual void Update() = 0;
	private:
	};

}