#pragma once

#include "..\Common.h"

namespace Maths {

	struct GE_API vec2
	{
		float X, Y;

		vec2() = default;
		vec2(float scalar);
		vec2(float x, float y);

		vec2& Add(const vec2& other);
		vec2& Subtract(const vec2& other);
		vec2& Multiply(const vec2& other);
		vec2& Divide(const vec2& other);
		vec2& Add(float scalar);
		vec2& Subtract(float scalar);
		vec2& Multiply(float scalar);
		vec2& Divide(float scalar);

		GE_API friend vec2 operator + (vec2 lhs, const vec2& rhs);
		GE_API friend vec2 operator - (vec2 lhs, const vec2& rhs);
		GE_API friend vec2 operator * (vec2 lhs, const vec2& rhs);
		GE_API friend vec2 operator / (vec2 lhs, const vec2& rhs);
		GE_API friend vec2 operator + (vec2 lhs, float scalar);
		GE_API friend vec2 operator - (vec2 lhs, float scalar);
		GE_API friend vec2 operator * (vec2 lhs, float scalar);
		GE_API friend vec2 operator / (vec2 lhs, float scalar);

		bool operator == (const vec2& other);
		bool operator != (const vec2& other);

		vec2& operator += (const vec2& rhs);
		vec2& operator -= (const vec2& rhs);
		vec2& operator *= (const vec2& rhs);
		vec2& operator /= (const vec2& rhs);
		vec2& operator += (float scalar);
		vec2& operator -= (float scalar);
		vec2& operator *= (float scalar);
		vec2& operator /= (float scalar);

		float Magnitude() const;
		vec2 Normalise() const;
	};

}