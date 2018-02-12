#pragma once

#include "..\Common.h"

namespace Maths {

	struct GE_API vec3
	{
		float X, Y, Z;

		vec3() = default;
		vec3(float scalar);
		vec3(float x, float y, float z);

		vec3& Add(const vec3& other);
		vec3& Subtract(const vec3& other);
		vec3& Multiply(const vec3& other);
		vec3& Divide(const vec3& other);

		friend vec3 operator + (vec3 lhs, const vec3& rhs);
		friend vec3 operator - (vec3 lhs, const vec3& rhs);
		friend vec3 operator * (vec3 lhs, const vec3& rhs);
		friend vec3 operator / (vec3 lhs, const vec3& rhs);

		bool operator == (const vec3& other);
		bool operator != (const vec3& other);

		vec3& operator += (const vec3& rhs);
		vec3& operator -= (const vec3& rhs);
		vec3& operator *= (const vec3& rhs);
		vec3& operator /= (const vec3& rhs);

		static vec3 Cross(const vec3& lhs, const vec3& rhs);
		static float Dot(const vec3& lhs, const vec3& rhs);

		float Magnitude() const;
		vec3 Normalise() const;
	};

}