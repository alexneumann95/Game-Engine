#include "vec3.h"

namespace Maths {

	vec3::vec3(float scalar) : X(scalar), Y(scalar), Z(scalar)
	{

	}

	vec3::vec3(float x, float y, float z) : X(x), Y(y), Z(z)
	{

	}

	vec3& vec3::Add(const vec3& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;

		return *this;
	}

	vec3& vec3::Subtract(const vec3& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;

		return *this;
	}

	vec3& vec3::Multiply(const vec3& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;

		return *this;
	}

	vec3& vec3::Divide(const vec3& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;

		return *this;
	}

	vec3& vec3::Add(float scalar)
	{
		X += scalar;
		Y += scalar;
		Z += scalar;

		return *this;
	}

	vec3& vec3::Subtract(float scalar)
	{
		X -= scalar;
		Y -= scalar;
		Z -= scalar;

		return *this;
	}

	vec3& vec3::Multiply(float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;

		return *this;
	}

	vec3& vec3::Divide(float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;

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

	vec3 operator + (vec3 lhs, float scalar)
	{
		return lhs.Add(scalar);
	}

	vec3 operator - (vec3 lhs, float scalar)
	{
		return lhs.Subtract(scalar);
	}

	vec3 operator * (vec3 lhs, float scalar)
	{
		return lhs.Multiply(scalar);
	}

	vec3 operator / (vec3 lhs, float scalar)
	{
		return lhs.Divide(scalar);
	}

	bool vec3::operator == (const vec3& other)
	{
		return (X == other.X && Y == other.Y && Z == other.Z);
	}

	bool vec3::operator != (const vec3& other)
	{
		return !(*this == other);
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

	vec3& vec3::operator += (float scalar)
	{
		return Add(scalar);
	}

	vec3& vec3::operator -= (float scalar)
	{
		return Subtract(scalar);
	}

	vec3& vec3::operator *= (float scalar)
	{
		return Multiply(scalar);
	}

	vec3& vec3::operator /= (float scalar)
	{
		return Divide(scalar);
	}

	vec3 vec3::Cross(const vec3& lhs, const vec3& rhs)
	{
		vec3 result;
		result.X = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
		result.Y = lhs.Z * rhs.X - lhs.X * rhs.Z;
		result.Z = lhs.X * rhs.Y - lhs.Y * rhs.X;
		return result;
	}

	float vec3::Dot(const vec3& lhs, const vec3& rhs)
	{
		return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
	}

	float vec3::Magnitude() const
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	vec3 vec3::Normalise() const
	{
		float length = Magnitude();
		return vec3(X / length, Y / length, Z / length);
	}

}