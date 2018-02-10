#include "vec3.h"

namespace Maths {

	vec3::vec3(float scalar) : X(scalar), Y(scalar), Z(scalar)
	{

	}

	vec3::vec3(float x, float y, float z) : X(x), Y(y), Z(z)
	{

	}

	vec3& vec3::Add(const vec3& rhs)
	{
		X += rhs.X;
		Y += rhs.Y;
		Z += rhs.Z;

		return *this;
	}

	vec3& vec3::Subtract(const vec3& rhs)
	{
		X -= rhs.X;
		Y -= rhs.Y;
		Z -= rhs.Z;

		return *this;
	}

	vec3& vec3::Multiply(const vec3& rhs)
	{
		X *= rhs.X;
		Y *= rhs.Y;
		Z *= rhs.Z;

		return *this;
	}

	vec3& vec3::Divide(const vec3& rhs)
	{
		X /= rhs.X;
		Y /= rhs.Y;
		Z /= rhs.Z;

		return *this;
	}

	vec3 operator + (vec3 lhs, const vec3& rhs)
	{
		return lhs.Add(rhs);
	}

	vec3 operator - (vec3 lhs, const vec3& rhs)
	{
		return lhs.Subtract(rhs);
	}

	vec3 operator * (vec3 lhs, const vec3& rhs)
	{
		return lhs.Multiply(rhs);
	}

	vec3 operator / (vec3 lhs, const vec3& rhs)
	{
		return lhs.Divide(rhs);
	}

	bool vec3::operator == (const vec3& rhs)
	{
		return (X == rhs.X && Y == rhs.Y && Z == rhs.Z);
	}

	bool vec3::operator != (const vec3& rhs)
	{
		return !(*this == rhs);
	}

	vec3& vec3::operator += (const vec3& rhs)
	{
		return Add(rhs);
	}

	vec3& vec3::operator -= (const vec3& rhs)
	{
		return Subtract(rhs);
	}

	vec3& vec3::operator *= (const vec3& rhs)
	{
		return Multiply(rhs);
	}

	vec3& vec3::operator /= (const vec3& rhs)
	{
		return Divide(rhs);
	}

}