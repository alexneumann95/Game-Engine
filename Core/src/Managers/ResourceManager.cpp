#include "ResourceManager.h"

namespace Managers {

	// RESOURCE MANAGER
	ResourceManager* ResourceManager::m_pInstance = nullptr;

	ResourceManager::ResourceManager()
	{
		assert(m_pInstance == nullptr);
		m_pInstance = this;
	}

	ResourceManager* ResourceManager::Instance()
	{
		return m_pInstance;
	}

	bool ResourceManager::Start()
	{
		return true;
	}

	bool ResourceManager::Stop()
	{
		for (auto& buffer : m_VertexBuffers)
			delete buffer.second;

		for (auto& buffer : m_ElementBuffers)
			delete buffer.second;

		return true;
	}

	void ResourceManager::Update()
	{
		
	}

	const string& ResourceManager::AddVertexBuffer(unsigned int bufferSize)
	{
		string RUID = RUID::NextVertexBufferRUID();
		std::pair<VertexBufferMap::iterator, bool> result = m_VertexBuffers.insert(std::pair<string, VertexBuffer*>(RUID, new VertexBuffer(bufferSize, RUID)));
		return result.first->first;
	}

	const string& ResourceManager::AddElementBuffer(unsigned int bufferSize)
	{
		string RUID = RUID::NextElementBufferRUID();
		std::pair<ElementBufferMap::iterator, bool> result = m_ElementBuffers.insert(std::pair<string, ElementBuffer*>(RUID, new ElementBuffer(bufferSize, RUID)));
		return result.first->first;
	}

	bool ResourceManager::CheckVertexBufferExists(const string& RUID)
	{
		return m_VertexBuffers.find(RUID) != m_VertexBuffers.end() ? true : false;
	}

	bool ResourceManager::CheckElementBufferExists(const string& RUID)
	{
		return m_ElementBuffers.find(RUID) != m_ElementBuffers.end() ? true : false;
	}

	// RUID
	int RUID::m_NextVertexBufferNo = 1;
	int RUID::m_NextElementBufferNo = 1;

	string RUID::NextVertexBufferRUID()
	{
		return "Resources.Buffers.Vertex." + m_NextVertexBufferNo++;
	}

	string RUID::NextElementBufferRUID()
	{
		return "Resources.Buffers.Element." + m_NextElementBufferNo++;
	}
}