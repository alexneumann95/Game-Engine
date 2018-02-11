#pragma once

#include "Manager.h"

namespace Managers {

	class GE_API FileManager final : public Manager
	{
	public:
		FileManager();
		static FileManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		const std::string& GetExeDirectory() const;
	private:
		void SetExeDirectory();
	private:
		static FileManager* m_pInstance;
		std::string m_ExeDirectory;
	};

}

#define FILE_MANAGER Managers::FileManager::Instance()