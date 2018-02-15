#pragma once

#include "..\Common.h"
#include "..\Maths\vec4.h"
#include "..\Maths\vec3.h"
#include "..\Maths\vec2.h"

namespace Graphics {

	struct GE_API Vertex
	{
		Maths::vec3 Position;
		Maths::vec4 Colour;
		Maths::vec2 TexCoord;

		Vertex(const Maths::vec3& pos, const Maths::vec4& colour, const Maths::vec2& texCoord) : Position(pos), Colour(colour), TexCoord(texCoord)
		{

		}
	};

}