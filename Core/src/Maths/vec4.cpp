#include "vec4.h"
#include "vec3.h"

namespace Maths {

	vec4::vec4(float scalar) : X(scalar), Y(scalar), Z(scalar), W(scalar)
	{

	}

	vec4::vec4(const vec3& vector, float w) : X(vector.X), Y(vector.Y), Z(vector.Z), W(w)
	{

	}

	vec4::vec4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w)
	{

	}

	vec4& vec4::Add(const vec4& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;
		W += other.W;

		return *this;
	}

	vec4& vec4::Subtract(const vec4& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
		W -= other.W;

		return *this;
	}

	vec4& vec4::Multiply(const vec4& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;
		W *= other.W;

		return *this;
	}

	vec4& vec4::Divide(const vec4& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;
		W /= other.W;

		return *this;
	}

	vec4& vec4::Add(float scalar)
	{
		X += scalar;
		Y += scalar;
		Z += scalar;
		W += scalar;

		return *this;
	}

	vec4& vec4::Subtract(float scalar)
	{
		X -= scalar;
		Y -= scalar;
		Z -= scalar;
		W -= scalar;

		return *this;
	}

	vec4& vec4::Multiply(float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;
		W *= scalar;

		return *this;
	}

	vec4& vec4::Divide(float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;
		W /= scalar;

		return *this;
	}

	vec4 operator + (vec4 lhs, const vec4& rhs)
	{
		return lhs.Add(rhs);
	}

	vec4 operator - (vec4 lhs, const vec4& rhs)
	{
		return lhs.Subtract(rhs);
	}

	vec4 operator * (vec4 lhs, const vec4& rhs)
	{
		return lhs.Multiply(rhs);
	}

	vec4 operator / (vec4 lhs, const vec4& rhs)
	{
		return lhs.Divide(rhs);
	}

	vec4 operator + (vec4 lhs, float scalar)
	{
		return lhs.Add(scalar);
	}

	vec4 operator - (vec4 lhs, float scalar)
	{
		return lhs.Subtract(scalar);
	}

	vec4 operator * (vec4 lhs, float scalar)
	{
		return lhs.Multiply(scalar);
	}

	vec4 operator / (vec4 lhs, float scalar)
	{
		return lhs.Divide(scalar);
	}

	bool vec4::operator == (const vec4& other)
	{
		return (X == other.X && Y == other.Y && Z == other.Z && W == other.W);
	}

	bool vec4::operator != (const vec4& other)
	{
		return !(*this == other);
	}

	vec4& vec4::operator += (const vec4& rhs)
	{
		return Add(rhs);
	}

	vec4& vec4::operator -= (const vec4& rhs)
	{
		return Subtract(rhs);
	}

	vec4& vec4::operator *= (const vec4& rhs)
	{
		return Multiply(rhs);
	}

	vec4& vec4::operator /= (const vec4& rhs)
	{
		return Divide(rhs);
	}

	vec4& vec4::operator += (float scalar)
	{
		return Add(scalar);
	}

	vec4& vec4::operator -= (float scalar)
	{
		return Subtract(scalar);
	}

	vec4& vec4::operator *= (float scalar)
	{
		return Multiply(scalar);
	}

	vec4& vec4::operator /= (float scalar)
	{
		return Divide(scalar);
	}

	vec4 vec4::Cross(const vec4& lhs, const vec4& rhs)
	{
		return vec4(vec3::Cross(vec3(lhs.X, lhs.Y, lhs.Z), vec3(rhs.X, rhs.Y, rhs.Z)), 1.0f);
	}

	float vec4::Dot(const vec4& lhs, const vec4& rhs)
	{
		return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W;
	}

	float vec4::Magnitude() const
	{
		return sqrt(X * X + Y * Y + Z * Z + W * W);
	}

	vec4 vec4::Normalise() const
	{
		float length = Magnitude();
		return vec4(X / length, Y / length, Z / length, W / length);
	}

}