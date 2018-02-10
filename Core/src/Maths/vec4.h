#pragma once

#include "..\Common.h"

namespace Maths {

	struct vec3;

	struct GE_API vec4
	{
		float X, Y, Z, W;

		vec4() = default;
		vec4(float scalar);
		vec4(const vec3& vector, float w);
		vec4(float x, float y, float z, float w);

		vec4& Add(const vec4& rhs);
		vec4& Subtract(const vec4& rhs);
		vec4& Multiply(const vec4& rhs);
		vec4& Divide(const vec4& rhs); 

		friend vec4 operator + (vec4 lhs, const vec4& rhs);
		friend vec4 operator - (vec4 lhs, const vec4& rhs);
		friend vec4 operator * (vec4 lhs, const vec4& rhs);
		friend vec4 operator / (vec4 lhs, const vec4& rhs);

		bool operator == (const vec4& rhs);
		bool operator != (const vec4& rhs);

		vec4& operator += (const vec4& rhs);
		vec4& operator -= (const vec4& rhs);
		vec4& operator *= (const vec4& rhs);
		vec4& operator /= (const vec4& rhs);
	};

}