#pragma once

#include "..\Common.h"
#include "vec4.h"
#include "vec3.h"

namespace Maths {

	struct GE_API mat4
	{
		union
		{
			float Elements[16];
			vec4 Cols[4];
		};

		mat4();
		mat4(float diagonal);
		mat4(const vec4& col0, const vec4& col1, const vec4& col2, const vec4& col3);

		mat4& Multiply(const mat4& other);

		GE_API friend mat4 operator * (mat4 lhs, const mat4& rhs);

		mat4& operator *= (const mat4& other);

		static mat4 Identity();
		static mat4 Translation(const vec3& translation);
		static mat4 Scale(const vec3& scale);
		static mat4 Rotation(float angle, const vec3& axis);
		static mat4 LookAt(const vec3& position, const vec3& object, const vec3& up = vec3(0.0f, 1.0f, 0.0f));
		static mat4 Perspective(float fov, float aspectRatio, float n, float f);

		GE_API friend std::ostream& operator << (std::ostream& os, const mat4& matrix);
	};

}