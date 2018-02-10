#pragma once

#include "Managers\ResourceManager.h"
#include "Managers\FileManager.h"

#include <vector>

namespace EngineControl
{
	std::vector<Managers::Manager*> Managers;

	bool EngineStartUp()
	{
		Managers.push_back(new Managers::FileManager());
		Managers.push_back(new Managers::ResourceManager());

		std::vector<Managers::Manager*>::iterator iter = Managers.begin();
		for (; iter != Managers.end(); ++iter)
		{
			if (!(*iter)->Start())
				return false;
		}

		return true;
	}

	bool EngineShutDown()
	{
		std::vector<Managers::Manager*>::reverse_iterator iter = Managers.rbegin();
		for (; iter != Managers.rend(); ++iter)
		{
			if (!(*iter)->Stop())
				return false;

			delete *iter;
		}

		return true;
	}

	void EngineUpdate()
	{
		std::vector<Managers::Manager*>::iterator iter = Managers.begin();
		for (; iter != Managers.end(); ++iter)
			(*iter)->Update();
	}
}

