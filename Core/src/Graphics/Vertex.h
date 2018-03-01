#pragma once

#include "..\Common.h"

#include <MathsLib\Containers\vec2.h>
#include <MathsLib\Containers\vec3.h>
#include <MathsLib\Containers\vec4.h>

using Maths::Containers::vec2;
using Maths::Containers::vec3;
using Maths::Containers::vec4;

namespace Graphics {

	struct GE_API Vertex
	{
		vec3<float> Position;
		vec3<float> Normal;
		vec4<float> Colour;
		vec2<float> TexCoord;

		Vertex(const vec3<float>& pos, const vec3<float>& normal, const vec4<float>& colour, const vec2<float>& texCoord) : Position(pos), Normal(normal), Colour(colour), TexCoord(texCoord)
		{

		}
	};

}