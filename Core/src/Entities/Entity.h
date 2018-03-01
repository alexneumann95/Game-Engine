#pragma once

#include "..\Common.h"
#include "EntityType.h"

namespace Entities {

	class GE_API Entity
	{
	public:
		Entity(const std::string& EUID, EntityType type);

		virtual Entity* Clone() const = 0;

		const std::string& GetEUID() const;
		EntityType GetType() const;

		virtual void Start() = 0;
		virtual void Update() = 0;
	private:
		const std::string m_EUID = "";
		EntityType m_Type;
	};

}