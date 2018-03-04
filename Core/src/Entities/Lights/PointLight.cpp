#include "PointLight.h"

namespace Entities::Lights {

	PointLight::PointLight(float constant, float linear, float quadratic, const vec3<float>& ambient, const vec3<float>& diffuse, const vec3<float>& specular)
		: Light(Managers::NextPointLightEUID(), EntityType::POINT_LIGHT, ambient, diffuse, specular), m_Constant(constant), m_Linear(linear), m_Quadratic(quadratic)
	{
		
	}

	PointLight::PointLight(const std::string& modelFileName, float constant, float linear, float quadratic, const vec3<float>& ambient, const vec3<float>& diffuse, const vec3<float>& specular)
		: Light(Managers::NextPointLightEUID(), EntityType::POINT_LIGHT, ambient, diffuse, specular), m_ModelFileName(modelFileName), m_Constant(constant), m_Linear(linear), m_Quadratic(quadratic)
	{
		
	}

	PointLight::PointLight(const PointLight& other) : Light(other.GetEUID(), EntityType::POINT_LIGHT, other.GetAmbient(), other.GetDiffuse(), other.GetSpecular()), 
		m_ModelFileName(other.m_ModelFileName), m_Constant(other.m_Constant), m_Linear(other.m_Linear), m_Quadratic(other.m_Quadratic)
	{
		AddComponent<Components::CTransform>(); // Every point light has a transform component (when added to the entity manager)
	}

	PointLight* PointLight::Clone() const
	{
		return new PointLight(*this);
	}

	void PointLight::Start()
	{
		if (m_ModelFileName != "")
		{
			AddComponent<Components::CModel>();
			GetComponent<Components::CModel>()->AddModelFile(m_ModelFileName);
			AddComponent<Components::CRender>();
		}
	}

	void PointLight::SetConstant(float value)
	{
		if (value <= 1.0f && value >= 0.0f)
			m_Constant = value;
	}

	void PointLight::SetLinear(float value)
	{
		if (value <= 1.0f && value >= 0.0f)
			m_Linear = value;
	}

	void PointLight::SetQuadratic(float value)
	{
		if (value <= 1.0f && value >= 0.0f)
			m_Quadratic = value;
	}

	float PointLight::GetConstant() const
	{
		return m_Constant;
	}

	float PointLight::GetLinear() const
	{
		return m_Linear;
	}

	float PointLight::GetQuadratic() const
	{
		return m_Quadratic;
	}

}