#pragma once

#include "Manager.h"
#include "..\Resources\Buffers\VertexBuffer.h"
#include "..\Resources\Buffers\ElementBuffer.h"

#include <map>
using namespace Resources::Buffers;

typedef std::map<string, VertexBuffer*> VertexBufferMap;
typedef std::map<string, ElementBuffer*> ElementBufferMap;

namespace Managers {

	class GE_API ResourceManager final : public Manager
	{
	public:
		ResourceManager();
		static ResourceManager* Instance();

		bool Start() override;
		bool Stop() override;
		void Update() override;

		const string& AddVertexBuffer(unsigned int bufferSize);
		const string& AddElementBuffer(unsigned int bufferSize);

		bool CheckVertexBufferExists(const string& RUID);
		bool CheckElementBufferExists(const string& RUID);
	private:
		static ResourceManager* m_pInstance;

		VertexBufferMap m_VertexBuffers;
		ElementBufferMap m_ElementBuffers;
	};

	class RUID final
	{
	public:
		static string NextVertexBufferRUID();
		static string NextElementBufferRUID();
	private:
		static int m_NextVertexBufferNo;
		static int m_NextElementBufferNo;
	};

}