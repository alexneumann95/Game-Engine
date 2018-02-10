#include "FileManager.h"
#include <Windows.h>

namespace Managers {

	FileManager* FileManager::m_pInstance = nullptr;

	FileManager::FileManager()
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;
	}

	FileManager* FileManager::Instance()
	{
		return m_pInstance;
	}

	bool FileManager::Start()
	{
		SetExeDirectory();

		return true;
	}

	bool FileManager::Stop()
	{
		return true;
	}

	void FileManager::Update()
	{

	}

	const std::string& FileManager::GetExeDirectory() const
	{
		return m_ExeDirectory;
	}

	void FileManager::SetExeDirectory()
	{
		char buffer[MAX_PATH];
		DWORD length = GetModuleFileName(NULL, buffer, MAX_PATH);

		m_ExeDirectory = std::string(buffer);
		m_ExeDirectory = m_ExeDirectory.substr(0, m_ExeDirectory.find_last_of('\\') + 1);
	}

}