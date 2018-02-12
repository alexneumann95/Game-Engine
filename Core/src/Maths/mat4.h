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
			vec4 Rows[4];
		};

		mat4();
		mat4(float diagonal);
		mat4(float* elements);
		mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3);

		mat4& Multiply(const mat4& other);

		friend mat4 operator * (mat4 lhs, const mat4& rhs);

		mat4& operator *= (const mat4& other);

		mat4& Invert();

		static mat4 Identity();
		static mat4 CreateFromTranslation(const vec3& translation);
		static mat4 CreateFromScale(const vec3& scale);
		static mat4 CreateFromRotation(float angle, const vec3& axis);
		static mat4 CreatePerspective(float fov, float aspectRatio, float n, float f);
		static mat4 CreateLookAt(const vec3& position, const vec3& focus, const vec3& up = vec3(0.0f, 1.0f, 0.0f));

		friend std::ostream& operator << (std::ostream& os, const mat4& matrix);
	};

}