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
		m_VertexBuffers.clear();

		for (auto& buffer : m_ElementBuffers)
			delete buffer.second;
		m_ElementBuffers.clear();

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

	VertexBuffer* const ResourceManager::GetVertexBuffer(const string& RUID)
	{
		auto iter = m_VertexBuffers.find(RUID);
		return iter != m_VertexBuffers.end() ? iter->second : nullptr;
	}

	ElementBuffer* const ResourceManager::GetElementBuffer(const string& RUID)
	{
		auto iter = m_ElementBuffers.find(RUID);
		return iter != m_ElementBuffers.end() ? iter->second : nullptr;
	}

	bool ResourceManager::DestroyVertexBuffer(const string& RUID)
	{
		if (!CheckVertexBufferExists(RUID))
			return false;

		auto iter = m_VertexBuffers.find(RUID);
		delete iter->second;
		m_VertexBuffers.erase(iter);

		return true;
	}

	bool ResourceManager::DestroyElementBuffer(const string& RUID)
	{
		if (!CheckElementBufferExists(RUID))
			return false;

		auto iter = m_ElementBuffers.find(RUID);
		delete iter->second;
		m_ElementBuffers.erase(iter);

		return true;
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