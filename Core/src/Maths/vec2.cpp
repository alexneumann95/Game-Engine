#include "vec2.h"

namespace Maths {

	vec2::vec2(float scalar) : X(scalar), Y(scalar)
	{

	}

	vec2::vec2(float x, float y) : X(x), Y(y)
	{

	}

	vec2& vec2::Add(const vec2& other)
	{
		X += other.X;
		Y += other.Y;

		return *this;
	}

	vec2& vec2::Subtract(const vec2& other)
	{
		X -= other.X;
		Y -= other.Y;

		return *this;
	}

	vec2& vec2::Multiply(const vec2& other)
	{
		X *= other.X;
		Y *= other.Y;

		return *this;
	}

	vec2& vec2::Divide(const vec2& other)
	{
		X /= other.X;
		Y /= other.Y;

		return *this;
	}

	vec2& vec2::Add(float scalar)
	{
		X += scalar;
		Y += scalar;

		return *this;
	}

	vec2& vec2::Subtract(float scalar)
	{
		X -= scalar;
		Y -= scalar;

		return *this;
	}

	vec2& vec2::Multiply(float scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}

	vec2& vec2::Divide(float scalar)
	{
		X /= scalar;
		Y /= scalar;

		return *this;
	}

	vec2 operator + (vec2 lhs, const vec2& rhs)
	{
		return lhs.Add(rhs);
	}

	vec2 operator - (vec2 lhs, const vec2& rhs)
	{
		return lhs.Subtract(rhs);
	}

	vec2 operator * (vec2 lhs, const vec2& rhs)
	{
		return lhs.Multiply(rhs);
	}

	vec2 operator / (vec2 lhs, const vec2& rhs)
	{
		return lhs.Divide(rhs);
	}

	vec2 operator + (vec2 lhs, float scalar)
	{
		return lhs.Add(scalar);
	}

	vec2 operator - (vec2 lhs, float scalar)
	{
		return lhs.Subtract(scalar);
	}

	vec2 operator * (vec2 lhs, float scalar)
	{
		return lhs.Multiply(scalar);
	}

	vec2 operator / (vec2 lhs, float scalar)
	{
		return lhs.Divide(scalar);
	}

	bool vec2::operator == (const vec2& other)
	{
		return (X == other.X && Y == other.Y);
	}

	bool vec2::operator != (const vec2& other)
	{
		return !(*this == other);
	}

	vec2& vec2::operator += (const vec2& rhs)
	{
		return Add(rhs);
	}

	vec2& vec2::operator -= (const vec2& rhs)
	{
		return Subtract(rhs);
	}

	vec2& vec2::operator *= (const vec2& rhs)
	{
		return Multiply(rhs);
	}

	vec2& vec2::operator /= (const vec2& rhs)
	{
		return Divide(rhs);
	}

	vec2& vec2::operator += (float scalar)
	{
		return Add(scalar);
	}

	vec2& vec2::operator -= (float scalar)
	{
		return Subtract(scalar);
	}

	vec2& vec2::operator *= (float scalar)
	{
		return Multiply(scalar);
	}

	vec2& vec2::operator /= (float scalar)
	{
		return Divide(scalar);
	}

	float vec2::Magnitude() const
	{
		return sqrt(X * X + Y * Y);
	}

	vec2 vec2::Normalise() const
	{
		float length = Magnitude();
		return vec2(X / length, Y / length);
	}

}