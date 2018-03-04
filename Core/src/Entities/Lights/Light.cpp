#include "Light.h"

namespace Entities::Lights {

	Light::Light(const std::string& EUID, EntityType type, const vec3<float>& ambient, const vec3<float>& diffuse, const vec3<float>& specular) : Entity(EUID, type),
		m_Ambient(ambient), m_Diffuse(diffuse), m_Specular(specular)
	{

	}

	void Light::SetAmbient(const vec3<float>& value)
	{
		m_Ambient = value;
	}

	void Light::SetDiffuse(const vec3<float>& value)
	{
		m_Diffuse = value;
	}

	void Light::SetSpecular(const vec3<float>& value)
	{
		m_Specular = value;
	}

	const vec3<float>& Light::GetAmbient() const
	{
		return m_Ambient;
	}

	const vec3<float>& Light::GetDiffuse() const
	{
		return m_Diffuse;
	}

	const vec3<float>& Light::GetSpecular() const
	{
		return m_Specular;
	}

}