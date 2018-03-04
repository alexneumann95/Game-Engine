#pragma once

#include "Light.h"

namespace Entities::Lights {

	class GE_API PointLight : public Light
	{
	public:
		PointLight(float constant = 1.0f, float linear = 0.09f, float quadratic = 0.032f, const vec3<float>& ambient = vec3<float>(0.1f, 0.1f, 0.1f),
			const vec3<float>& diffuse = vec3<float>(0.75f, 0.75f, 0.75f), const vec3<float>& specular = vec3<float>(1.0f, 1.0f, 1.0f));
		PointLight(const std::string& modelFileName, float constant = 1.0f, float linear = 0.09f, float quadratic = 0.032f, const vec3<float>& ambient = vec3<float>(0.1f, 0.1f, 0.1f),
			const vec3<float>& diffuse = vec3<float>(0.75f, 0.75f, 0.75f), const vec3<float>& specular = vec3<float>(1.0f, 1.0f, 1.0f));
		PointLight(const PointLight& other);

		virtual PointLight* Clone() const;

		void Start() override;
		void Update() override { }

		void SetConstant(float value);
		void SetLinear(float value);
		void SetQuadratic(float value);

		float GetConstant() const;
		float GetLinear() const;
		float GetQuadratic() const;
	private:
		std::string m_ModelFileName = ""; // If point light has a model associated with it
		float m_Constant;
		float m_Linear;
		float m_Quadratic;
	};

}

#define POINT_LIGHT_CLONE_METHOD(className) virtual Entities::Lights::PointLight* Clone() const { return new className(*this); }