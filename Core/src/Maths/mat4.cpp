#include "mat4.h"

namespace Maths {

	mat4::mat4()
	{
		memset(Elements, 0, 16 * sizeof(float));
	}

	mat4::mat4(float diagonal)
	{
		memset(Elements, 0, 16 * sizeof(float));
		Elements[0] = diagonal;
		Elements[5] = diagonal;
		Elements[10] = diagonal;
		Elements[15] = diagonal;
	}

	mat4::mat4(const vec4& col0, const vec4& col1, const vec4& col2, const vec4& col3)
	{
		Cols[0] = col0;
		Cols[1] = col1;
		Cols[2] = col2;
		Cols[3] = col3;
	}

	mat4& mat4::Multiply(const mat4& other)
	{
		float data[16];
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; i++)
					sum += Elements[i * 4 + row] * other.Elements[i + col * 4];
				data[row + col * 4] = sum;
			}
		}
		memcpy(Elements, data, 16 * sizeof(float));
		return *this;
	}

	mat4 operator * (mat4 lhs, const mat4& rhs)
	{
		return lhs.Multiply(rhs);
	}

	mat4& mat4::operator *= (const mat4& other)
	{
		return Multiply(other);
	}

	mat4 mat4::Identity()
	{
		return mat4(1.0f);
	}

	mat4 mat4::Translation(const vec3& translation)
	{
		mat4 result(1.0f);

		result.Elements[12] = translation.X;
		result.Elements[13] = translation.Y;
		result.Elements[14] = translation.Z;

		return result;
	}

	mat4 mat4::Scale(const vec3& scale)
	{
		mat4 result(1.0f);

		result.Elements[0] = scale.X;
		result.Elements[5] = scale.Y;
		result.Elements[10] = scale.Z;

		return result;
	}

	mat4 mat4::Rotation(float angle, const vec3& axis)
	{
		float c = cos(angle * 0.0174533f);
		float s = sin(angle * 0.0174533f);
		float omc = 1 - c;
		float x = axis.Normalise().X;
		float y = axis.Normalise().Y;
		float z = axis.Normalise().Z;

		mat4 result {
			vec4(c + x*x*omc, y*x*omc + z*s, z*x*omc - y*s, 0.0f),
			vec4(x*y*omc - z*s, c + y*y*omc, z*y*omc + x*s, 0.0f),
			vec4(x*z*omc + y*s, y*z*omc - x*s, c + z*z*omc, 0.0f),
			vec4(0.0f, 0.0f, 0.0f, 1.0f)
		};

		return result;
	}

	mat4 mat4::LookAt(const vec3& position, const vec3& centre, const vec3& up)
	{
		vec3 f = (centre - position).Normalise();
		vec3 r = vec3::Cross(f, up).Normalise();
		vec3 u = vec3::Cross(r, f).Normalise();

		mat4 ViewMatrix {
			vec4(r.X, u.X, -f.X, 0.0f),
			vec4(r.Y, u.Y, -f.Y, 0.0f),
			vec4(r.Z, u.Z, -f.Z, 0.0f),
			vec4(-vec3::Dot(r, position), -vec3::Dot(u, position), vec3::Dot(f, position), 1.0f)
		};

		return ViewMatrix;
	}

	mat4 mat4::Perspective(float fov, float aspectRatio, float n, float f)
	{
		float t = n * (float)tan(0.5 * fov * 0.0174533f);
		float r = t * aspectRatio;
	
		mat4 perspectiveMatrix = {
			vec4(n/r, 0.0f, 0.0f, 0.0f),
			vec4(0.0f, n/t, 0.0f, 0.0f),
			vec4(0.0f, 0.0f, -(f+n)/(f-n), -1.0f),
			vec4(0.0f, 0.0f, (-2.0f*f*n)/(f-n), 0.0f)
		};

		return perspectiveMatrix;
	}

	std::ostream& operator << (std::ostream& os, const mat4& matrix)
	{
		for (int i = 0; i < 16; i++)
		{
			os << matrix.Elements[i] << "\t";
			if (i == 3 || i == 7 || i == 11 || i == 15)
				os << "\n";
		}
		return os;
	}

}