#include "GameTimer.h"

namespace Utilities {

	GameTimer::GameTimer()
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&m_PerformanceFrequency);
	}

	void GameTimer::Tick()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&m_CurrentCount);
		m_DeltaCount = m_CurrentCount - m_LastCount;
		m_LastCount = m_CurrentCount;
	}

	float GameTimer::GetDeltaTime() const
	{
		return (float)m_DeltaCount / (float)m_PerformanceFrequency;
	}

}