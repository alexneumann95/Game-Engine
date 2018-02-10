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

	vec4& vec4::Add(const vec4& rhs)
	{
		X += rhs.X;
		Y += rhs.Y;
		Z += rhs.Z;
		W += rhs.W;

		return *this;
	}

	vec4& vec4::Subtract(const vec4& rhs)
	{
		X -= rhs.X;
		Y -= rhs.Y;
		Z -= rhs.Z;
		W -= rhs.W;

		return *this;
	}

	vec4& vec4::Multiply(const vec4& rhs)
	{
		X *= rhs.X;
		Y *= rhs.Y;
		Z *= rhs.Z;
		W *= rhs.W;

		return *this;
	}

	vec4& vec4::Divide(const vec4& rhs)
	{
		X /= rhs.X;
		Y /= rhs.Y;
		Z /= rhs.Z;
		W /= rhs.W;

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

	bool vec4::operator == (const vec4& rhs)
	{
		return (X == rhs.X && Y == rhs.Y && Z == rhs.Z && W == rhs.W);
	}

	bool vec4::operator != (const vec4& rhs)
	{
		return !(*this == rhs);
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

}