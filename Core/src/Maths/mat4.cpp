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

	mat4::mat4(float* elements)
	{
		memcpy(this->Elements, elements, 16 * sizeof(float));
	}

	mat4::mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3)
	{
		Rows[0] = row0;
		Rows[1] = row1;
		Rows[2] = row2;
		Rows[3] = row3;
	}

	mat4& mat4::Multiply(const mat4& other)
	{
		float data[16];

		for (int row = 0; row < 4; ++row)
		{
			for (int col = 0; col < 4; ++col)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; ++i)
					sum += this->Elements[i + row * 4] * other.Elements[col + i * 4];
				data[col + row * 4] = sum;
			}
		}
		memcpy(this->Elements, data, 16 * sizeof(float));
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

	mat4& mat4::Invert()
	{
		float temp[16];

		temp[0] = Elements[5] * Elements[10] * Elements[15] -
			Elements[5] * Elements[11] * Elements[14] -
			Elements[9] * Elements[6] * Elements[15] +
			Elements[9] * Elements[7] * Elements[14] +
			Elements[13] * Elements[6] * Elements[11] -
			Elements[13] * Elements[7] * Elements[10];

		temp[4] = -Elements[4] * Elements[10] * Elements[15] +
			Elements[4] * Elements[11] * Elements[14] +
			Elements[8] * Elements[6] * Elements[15] -
			Elements[8] * Elements[7] * Elements[14] -
			Elements[12] * Elements[6] * Elements[11] +
			Elements[12] * Elements[7] * Elements[10];

		temp[8] = Elements[4] * Elements[9] * Elements[15] -
			Elements[4] * Elements[11] * Elements[13] -
			Elements[8] * Elements[5] * Elements[15] +
			Elements[8] * Elements[7] * Elements[13] +
			Elements[12] * Elements[5] * Elements[11] -
			Elements[12] * Elements[7] * Elements[9];

		temp[12] = -Elements[4] * Elements[9] * Elements[14] +
			Elements[4] * Elements[10] * Elements[13] +
			Elements[8] * Elements[5] * Elements[14] -
			Elements[8] * Elements[6] * Elements[13] -
			Elements[12] * Elements[5] * Elements[10] +
			Elements[12] * Elements[6] * Elements[9];

		temp[1] = -Elements[1] * Elements[10] * Elements[15] +
			Elements[1] * Elements[11] * Elements[14] +
			Elements[9] * Elements[2] * Elements[15] -
			Elements[9] * Elements[3] * Elements[14] -
			Elements[13] * Elements[2] * Elements[11] +
			Elements[13] * Elements[3] * Elements[10];

		temp[5] = Elements[0] * Elements[10] * Elements[15] -
			Elements[0] * Elements[11] * Elements[14] -
			Elements[8] * Elements[2] * Elements[15] +
			Elements[8] * Elements[3] * Elements[14] +
			Elements[12] * Elements[2] * Elements[11] -
			Elements[12] * Elements[3] * Elements[10];

		temp[9] = -Elements[0] * Elements[9] * Elements[15] +
			Elements[0] * Elements[11] * Elements[13] +
			Elements[8] * Elements[1] * Elements[15] -
			Elements[8] * Elements[3] * Elements[13] -
			Elements[12] * Elements[1] * Elements[11] +
			Elements[12] * Elements[3] * Elements[9];

		temp[13] = Elements[0] * Elements[9] * Elements[14] -
			Elements[0] * Elements[10] * Elements[13] -
			Elements[8] * Elements[1] * Elements[14] +
			Elements[8] * Elements[2] * Elements[13] +
			Elements[12] * Elements[1] * Elements[10] -
			Elements[12] * Elements[2] * Elements[9];

		temp[2] = Elements[1] * Elements[6] * Elements[15] -
			Elements[1] * Elements[7] * Elements[14] -
			Elements[5] * Elements[2] * Elements[15] +
			Elements[5] * Elements[3] * Elements[14] +
			Elements[13] * Elements[2] * Elements[7] -
			Elements[13] * Elements[3] * Elements[6];

		temp[6] = -Elements[0] * Elements[6] * Elements[15] +
			Elements[0] * Elements[7] * Elements[14] +
			Elements[4] * Elements[2] * Elements[15] -
			Elements[4] * Elements[3] * Elements[14] -
			Elements[12] * Elements[2] * Elements[7] +
			Elements[12] * Elements[3] * Elements[6];

		temp[10] = Elements[0] * Elements[5] * Elements[15] -
			Elements[0] * Elements[7] * Elements[13] -
			Elements[4] * Elements[1] * Elements[15] +
			Elements[4] * Elements[3] * Elements[13] +
			Elements[12] * Elements[1] * Elements[7] -
			Elements[12] * Elements[3] * Elements[5];

		temp[14] = -Elements[0] * Elements[5] * Elements[14] +
			Elements[0] * Elements[6] * Elements[13] +
			Elements[4] * Elements[1] * Elements[14] -
			Elements[4] * Elements[2] * Elements[13] -
			Elements[12] * Elements[1] * Elements[6] +
			Elements[12] * Elements[2] * Elements[5];

		temp[3] = -Elements[1] * Elements[6] * Elements[11] +
			Elements[1] * Elements[7] * Elements[10] +
			Elements[5] * Elements[2] * Elements[11] -
			Elements[5] * Elements[3] * Elements[10] -
			Elements[9] * Elements[2] * Elements[7] +
			Elements[9] * Elements[3] * Elements[6];

		temp[7] = Elements[0] * Elements[6] * Elements[11] -
			Elements[0] * Elements[7] * Elements[10] -
			Elements[4] * Elements[2] * Elements[11] +
			Elements[4] * Elements[3] * Elements[10] +
			Elements[8] * Elements[2] * Elements[7] -
			Elements[8] * Elements[3] * Elements[6];

		temp[11] = -Elements[0] * Elements[5] * Elements[11] +
			Elements[0] * Elements[7] * Elements[9] +
			Elements[4] * Elements[1] * Elements[11] -
			Elements[4] * Elements[3] * Elements[9] -
			Elements[8] * Elements[1] * Elements[7] +
			Elements[8] * Elements[3] * Elements[5];

		temp[15] = Elements[0] * Elements[5] * Elements[10] -
			Elements[0] * Elements[6] * Elements[9] -
			Elements[4] * Elements[1] * Elements[10] +
			Elements[4] * Elements[2] * Elements[9] +
			Elements[8] * Elements[1] * Elements[6] -
			Elements[8] * Elements[2] * Elements[5];

		float determinant = Elements[0] * temp[0] + Elements[1] * temp[4] + Elements[2] * temp[8] + Elements[3] * temp[12];
		determinant = 1.0f / determinant;

		for (int i = 0; i < 16; i++)
			Elements[i] = temp[i] * determinant;

		return *this;
	}

	mat4 mat4::Identity()
	{
		return mat4(1.0f);
	}

	mat4 mat4::CreateFromTranslation(const vec3& translation)
	{
		mat4 result(1.0f);
		result.Elements[3] = translation.X;
		result.Elements[7] = translation.Y;
		result.Elements[11] = translation.Z;
		return result;
	}

	mat4 mat4::CreateFromScale(const vec3& scale)
	{
		mat4 result(1.0f);
		result.Elements[0] = scale.X;
		result.Elements[5] = scale.Y;
		result.Elements[10] = scale.Z;
		return result;
	}

	mat4 mat4::CreateFromRotation(float angle, const vec3& axis)
	{
		mat4 result(1.0f);

		float c = cos(angle * 0.0174533f);
		float s = sin(angle * 0.0174533f);
		float omc = 1.0f - c;

		float x = axis.X;
		float y = axis.Y;
		float z = axis.Z;

		result.Elements[0] = c + x*x*omc;
		result.Elements[4] = y*x*omc + z*s;
		result.Elements[8] = z*x*omc - y*s;

		result.Elements[1] = x*y*omc - z*s;
		result.Elements[5] = c + y*y*omc;
		result.Elements[9] = z*y*omc + x*s;

		result.Elements[2] = x*z*omc + y*s;
		result.Elements[6] = y*z*omc - x*s;
		result.Elements[10] = c + z*z*omc;

		return result;
	}

	mat4 mat4::CreatePerspective(float fov, float aspectRatio, float n, float f)
	{
		mat4 result(1.0f);

		float s = 1.0f / (float)tan((0.5 * fov) * 0.0174533f);

		result.Elements[0] = s;
		result.Elements[5] = s / aspectRatio;
		result.Elements[10] = (n + f) / (n - f);
		result.Elements[11] = -1.0f;
		result.Elements[14] = (2.0f * n * f) / (n - f);

		return result;
	}

	mat4 mat4::CreateLookAt(const vec3& position, const vec3& focus, const vec3& up)
	{
		mat4 result = Identity();

		vec3 f = (position - focus).Normalise();
		vec3 r = vec3::Cross(up.Normalise(), f);
		vec3 u = vec3::Cross(f, r);

		result.Elements[0] = r.X;
		result.Elements[1] = r.Y;
		result.Elements[2] = r.Z;
		result.Elements[4] = u.X;
		result.Elements[5] = u.Y;
		result.Elements[6] = u.Z;
		result.Elements[8] = f.X;
		result.Elements[9] = f.Y;
		result.Elements[10] = f.Z;

		result.Elements[12] = position.X;
		result.Elements[13] = position.Y;
		result.Elements[14] = position.Z;

		return result;
	}

	std::ostream& operator << (std::ostream& os, const mat4& matrix)
	{
		for (int row = 0; row < 4; ++row)
		{
			for (int col = 0; col < 4; ++col)
			{
				os << matrix.Elements[col + row * 4] << "\t";
			}
			os << "\n";
		}

		return os;
	}

}