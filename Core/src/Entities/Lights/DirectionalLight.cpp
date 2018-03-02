#include "DirectionalLight.h"

namespace Entities::Lights {

	DirectionalLight::DirectionalLight(const vec3<float>& direction, const vec3<float>& ambient, const vec3<float>& diffuse, const vec3<float>& specular) :
		Entity(Managers::NextDirectionalLightEUID(), EntityType::DIRECTIONAL_LIGHT), m_Direction(direction), m_Ambient(ambient), m_Diffuse(diffuse), m_Specular(specular)
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

	void DirectionalLight::SetAmbient(const vec3<float>& value)
	{
		m_Ambient = value;
	}

	void DirectionalLight::SetDiffuse(const vec3<float>& value)
	{
		m_Diffuse = value;
	}

	void DirectionalLight::SetSpecular(const vec3<float>& value)
	{
		m_Specular = value;
	}

	const vec3<float>& DirectionalLight::GetDirection() const
	{
		return m_Direction;
	}

	const vec3<float>& DirectionalLight::GetAmbient() const
	{
		return m_Ambient;
	}

	const vec3<float>& DirectionalLight::GetDiffuse() const
	{
		return m_Diffuse;
	}

	const vec3<float>& DirectionalLight::GetSpecular() const
	{
		return m_Specular;
	}

}