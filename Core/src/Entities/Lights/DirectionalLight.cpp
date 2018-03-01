#include "DirectionalLight.h"

namespace Entities::Lights {

	DirectionalLight::DirectionalLight(const std::string& EUID) : Entity(EUID, EntityType::DIRECTIONAL_LIGHT)
	{

	}

	DirectionalLight::DirectionalLight(const vec3<float>& direction, const vec3<float>& colour, const std::string& EUID) :
		Entity(EUID, EntityType::DIRECTIONAL_LIGHT), m_Direction(direction), m_Colour(colour)
	{

	}

	DirectionalLight* DirectionalLight::Clone() const
	{
		return new DirectionalLight(*this);
	}

	void DirectionalLight::SetDirection(const vec3<float>& direction)
	{
		if (direction != vec3<float>(0.0f, 0.0f, 0.0f))
			m_Direction = direction;
	}

	void DirectionalLight::SetColour(const vec3<float>& colour)
	{
		m_Colour = colour;
	}

	const vec3<float>& DirectionalLight::GetDirection() const
	{
		return m_Direction;
	}

	const vec3<float>& DirectionalLight::GetColour() const
	{
		return m_Colour;
	}

}