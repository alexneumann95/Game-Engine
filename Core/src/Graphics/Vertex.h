#pragma once

#include "..\Common.h"
#include "..\Maths\vec4.h"
#include "..\Maths\vec3.h"

namespace Graphics {

	struct GE_API Vertex
	{
		Maths::vec3 Position;
		Maths::vec4 Colour;

		Vertex(const Maths::vec3& pos, const Maths::vec4& colour) : Position(pos), Colour(colour)
		{

		}
	};

}