#pragma once

#include "Manager.h"
#include "RUID.h"
#include "..\Resources\Buffers\RVertexBuffer.h"
#include "..\Resources\Buffers\RElementBuffer.h"
#include "..\Resources\RModel.h"
#include "..\Resources\RTexture.h"

#include <map>

typedef std::map<std::string, Resources::Buffers::RVertexBuffer*> VertexBufferMap;
typedef std::map<std::string, Resources::Buffers::RElementBuffer*> ElementBufferMap;
typedef std::map<std::string, Resources::RModel*> ModelMap;
typedef std::map<std::string, Resources::RTexture*> TextureMap;

namespace Managers {

	class GE_API ResourceManager final : public Manager
	{
	public:
		ResourceManager();
		static ResourceManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		const std::string& AddVertexBuffer(unsigned int bufferSize);
		const std::string& AddElementBuffer(unsigned int count);
		const std::string& AddModel(const std::string& file);
		const std::string& AddTexture(const std::string& file);

		bool CheckVertexBufferExists(const std::string& RUID);
		bool CheckElementBufferExists(const std::string& RUID);
		bool CheckModelExists(const std::string& RUID);
		bool CheckTextureExists(const std::string& RUID);

		Resources::Buffers::RVertexBuffer* const GetVertexBuffer(const std::string& RUID);
		Resources::Buffers::RElementBuffer* const GetElementBuffer(const std::string& RUID);
		Resources::RModel* const GetModel(const std::string& RUID);
		Resources::RTexture* const GetTexture(const std::string& RUID);

		bool DestroyVertexBuffer(const std::string& RUID);
		bool DestroyElementBuffer(const std::string& RUID);
		bool DestroyModel(const std::string& RUID);
		bool DestroyTexture(const std::string& RUID);
	private:
		static ResourceManager* m_pInstance;

		VertexBufferMap m_VertexBuffers;
		ElementBufferMap m_ElementBuffers;
		ModelMap m_Models;
		TextureMap m_Textures;
	};

}

#define RESOURCE_MANAGER Managers::ResourceManager::Instance()