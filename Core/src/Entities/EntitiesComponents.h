/*
	Describes the components allowed for different types of entities
*/
#pragma once

#include "..\Components\ComponentType.h"

#include <vector>

namespace Entities {

	const std::vector<Components::ComponentType> GAME_OBJECT_ALLOWED_COMPONENTS =
	{
		Components::ComponentType::TRANSFORM,
		Components::ComponentType::MODEL,
		Components::ComponentType::RENDER
	};

	const std::vector<Components::ComponentType> POINT_LIGHT_ALLOWED_COMPONENTS =
	{
		Components::ComponentType::TRANSFORM,
		Components::ComponentType::MODEL,
		Components::ComponentType::RENDER
	};

}