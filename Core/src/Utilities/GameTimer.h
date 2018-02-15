#pragma once

#include "..\Common.h"

#include <Windows.h>

namespace Utilities {

	class GE_API GameTimer final
	{
	public:
		GameTimer();

		void Tick();

		float GetDeltaTime() const;
	private:
		__int64 m_PerformanceFrequency;
		__int64 m_CurrentCount = 0;
		__int64 m_LastCount = 0;
		__int64 m_DeltaCount = 0;
	};

}