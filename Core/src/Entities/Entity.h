#pragma once

#include "..\Common.h"

namespace Entities {

	class GE_API Entity
	{
	public:
		Entity(const std::string& EUID);

		const std::string& GetEUID() const;

		virtual void Start() = 0;
		virtual void Update() = 0;
	private:
		const std::string m_EUID = "";
	};

}