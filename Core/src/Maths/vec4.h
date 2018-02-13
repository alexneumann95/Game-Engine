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

		vec4& Add(const vec4& other);
		vec4& Subtract(const vec4& other);
		vec4& Multiply(const vec4& other);
		vec4& Divide(const vec4& other);
		vec4& Add(float scalar);
		vec4& Subtract(float scalar);
		vec4& Multiply(float scalar);
		vec4& Divide(float scalar);

		GE_API friend vec4 operator + (vec4 lhs, const vec4& rhs);
		GE_API friend vec4 operator - (vec4 lhs, const vec4& rhs);
		GE_API friend vec4 operator * (vec4 lhs, const vec4& rhs);
		GE_API friend vec4 operator / (vec4 lhs, const vec4& rhs);
		GE_API friend vec4 operator + (vec4 lhs, float scalar);
		GE_API friend vec4 operator - (vec4 lhs, float scalar);
		GE_API friend vec4 operator * (vec4 lhs, float scalar);
		GE_API friend vec4 operator / (vec4 lhs, float scalar);

		bool operator == (const vec4& other);
		bool operator != (const vec4& other);

		vec4& operator += (const vec4& rhs);
		vec4& operator -= (const vec4& rhs);
		vec4& operator *= (const vec4& rhs);
		vec4& operator /= (const vec4& rhs);
		vec4& operator += (float scalar);
		vec4& operator -= (float scalar);
		vec4& operator *= (float scalar);
		vec4& operator /= (float scalar);

		static vec4 Cross(const vec4& lhs, const vec4& rhs);
		static float Dot(const vec4& lhs, const vec4& rhs);

		float Magnitude() const;
		vec4 Normalise() const;
	};

}