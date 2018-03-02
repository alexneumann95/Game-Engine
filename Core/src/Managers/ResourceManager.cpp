#include "ResourceManager.h"

namespace Managers {

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
		for (auto iter : m_VertexBuffers)
			delete iter.second;
		m_VertexBuffers.clear();

		for (auto iter : m_ElementBuffers)
			delete iter.second;
		m_ElementBuffers.clear();

		for (auto iter : m_Models)
			delete iter.second;
		m_Models.clear();

		for (auto iter : m_Textures)
			delete iter.second;
		m_Textures.clear();

		return true;
	}

	void ResourceManager::Update()
	{
		
	}

	const std::string& ResourceManager::AddVertexBuffer(unsigned int bufferSize)
	{
		std::string RUID = NextVertexBufferRUID();
		std::pair<VertexBufferMap::iterator, bool> result = m_VertexBuffers.insert(std::pair<std::string, Resources::Buffers::RVertexBuffer*>(RUID, new Resources::Buffers::RVertexBuffer(bufferSize, RUID)));
		result.first->second->Init();

		return result.first->first;
	}

	const std::string& ResourceManager::AddElementBuffer(unsigned int count)
	{
		std::string RUID = NextElementBufferRUID();
		std::pair<ElementBufferMap::iterator, bool> result = m_ElementBuffers.insert(std::pair<std::string, Resources::Buffers::RElementBuffer*>(RUID, new Resources::Buffers::RElementBuffer(count, RUID)));
		result.first->second->Init();
		return result.first->first;
	}

	const std::string& ResourceManager::AddModel(const std::string& file)
	{
		std::string RUID = GenModelRUID(file);
		if (CheckModelExists(RUID))
			return m_Models.find(RUID)->first;

		std::pair<ModelMap::iterator, bool> result = m_Models.insert(std::pair<std::string, Resources::RModel*>(RUID, new Resources::RModel(file, RUID)));
		result.first->second->Init();
		return result.first->first;
	}

	const std::string& ResourceManager::AddTexture(const std::string& file)
	{
		std::string RUID = GenTextureRUID(file);
		if (CheckTextureExists(RUID))
			return m_Textures.find(RUID)->first;

		std::pair<TextureMap::iterator, bool> result = m_Textures.insert(std::pair<std::string, Resources::RTexture*>(RUID, new Resources::RTexture(file, RUID)));
		result.first->second->Init();
		return result.first->first;
	}

	bool ResourceManager::CheckVertexBufferExists(const std::string& RUID)
	{
		return m_VertexBuffers.find(RUID) != m_VertexBuffers.end() ? true : false;
	}

	bool ResourceManager::CheckElementBufferExists(const std::string& RUID)
	{
		return m_ElementBuffers.find(RUID) != m_ElementBuffers.end() ? true : false;
	}

	bool ResourceManager::CheckModelExists(const std::string& RUID)
	{
		return m_Models.find(RUID) != m_Models.end() ? true : false;
	}

	bool ResourceManager::CheckTextureExists(const std::string& RUID)
	{
		return m_Textures.find(RUID) != m_Textures.end() ? true : false;
	}

	Resources::Buffers::RVertexBuffer* const ResourceManager::GetVertexBuffer(const std::string& RUID)
	{
		auto iter = m_VertexBuffers.find(RUID);
		return iter != m_VertexBuffers.end() ? iter->second : nullptr;
	}

	Resources::Buffers::RElementBuffer* const ResourceManager::GetElementBuffer(const std::string& RUID)
	{
		auto iter = m_ElementBuffers.find(RUID);
		return iter != m_ElementBuffers.end() ? iter->second : nullptr;
	}

	Resources::RModel* const ResourceManager::GetModel(const std::string& RUID)
	{
		auto iter = m_Models.find(RUID);
		return iter != m_Models.end() ? iter->second : nullptr;
	}

	Resources::RTexture* const ResourceManager::GetTexture(const std::string& RUID)
	{
		auto iter = m_Textures.find(RUID);
		return iter != m_Textures.end() ? iter->second : nullptr;
	}

	bool ResourceManager::DestroyVertexBuffer(const std::string& RUID)
	{
		if (!CheckVertexBufferExists(RUID))
			return false;

		auto iter = m_VertexBuffers.find(RUID);
		delete iter->second;
		m_VertexBuffers.erase(iter);

		return true;
	}

	bool ResourceManager::DestroyElementBuffer(const std::string& RUID)
	{
		if (!CheckElementBufferExists(RUID))
			return false;

		auto iter = m_ElementBuffers.find(RUID);
		delete iter->second;
		m_ElementBuffers.erase(iter);

		return true;
	}

	bool ResourceManager::DestroyModel(const std::string& RUID)
	{
		if (!CheckModelExists(RUID))
			return false;

		auto iter = m_Models.find(RUID);
		delete iter->second;
		m_Models.erase(iter);

		return true;
	}

	bool ResourceManager::DestroyTexture(const std::string& RUID)
	{
		if (!CheckTextureExists(RUID))
			return false;

		auto iter = m_Textures.find(RUID);
		delete iter->second;
		m_Textures.erase(iter);

		return true;
	}

}