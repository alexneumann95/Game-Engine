#include "DirectionalLight.h"

namespace Entities::Lights {

	DirectionalLight::DirectionalLight(const vec3<float>& direction, const vec3<float>& ambient, const vec3<float>& diffuse, const vec3<float>& specular) :
		Light(Managers::NextDirectionalLightEUID(), EntityType::DIRECTIONAL_LIGHT, ambient, diffuse, specular), m_Direction(direction)
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

	const vec3<float>& DirectionalLight::GetDirection() const
	{
		return m_Direction;
	}

}