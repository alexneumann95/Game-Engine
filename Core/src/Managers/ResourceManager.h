#pragma once

#include "Manager.h"
#include "..\Resources\Buffers\VertexBuffer.h"
#include "..\Resources\Buffers\ElementBuffer.h"
#include "..\Resources\Model.h"

#include <map>
using namespace Resources;
using namespace Resources::Buffers;

typedef std::map<std::string, VertexBuffer*> VertexBufferMap;
typedef std::map<std::string, ElementBuffer*> ElementBufferMap;
typedef std::map<std::string, Model*> ModelMap;

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

		bool CheckVertexBufferExists(const std::string& RUID);
		bool CheckElementBufferExists(const std::string& RUID);
		bool CheckModelExists(const std::string& RUID);

		VertexBuffer* const GetVertexBuffer(const std::string& RUID);
		ElementBuffer* const GetElementBuffer(const std::string& RUID);
		Model* const GetModel(const std::string& RUID);

		bool DestroyVertexBuffer(const std::string& RUID);
		bool DestroyElementBuffer(const std::string& RUID);
		bool DestroyModel(const std::string& RUID);
	private:
		static ResourceManager* m_pInstance;

		VertexBufferMap m_VertexBuffers;
		ElementBufferMap m_ElementBuffers;
		ModelMap m_Models;
	};

	class RUID final
	{
	public:
		static std::string NextVertexBufferRUID();
		static std::string NextElementBufferRUID();
		static std::string GenModelRUID(const std::string& file);
	private:
		static int m_NextVertexBufferNo;
		static int m_NextElementBufferNo;
	};

}