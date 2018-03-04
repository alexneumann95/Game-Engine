#pragma once

#include "Light.h"

namespace Entities::Lights {

	class GE_API DirectionalLight : public Light
	{
	public:
		DirectionalLight(const vec3<float>& direction = vec3<float>(0.0f, -1.0f, 0.0f), const vec3<float>& ambient = vec3<float>(0.25f, 0.25f, 0.25f), 
			const vec3<float>& diffuse = vec3<float>(0.75f, 0.75f, 0.75f), const vec3<float>& specular = vec3<float>(1.0f, 1.0f, 1.0f));

		virtual DirectionalLight* Clone() const;

		void Start() override { }
		void Update() override { }

		void SetDirection(const vec3<float>& direction);
		const vec3<float>& GetDirection() const;
	private:
		vec3<float> m_Direction; // Direction from "light position" to scene
	};

}

#define DIRECTIONAL_LIGHT_CLONE_METHOD(className) virtual Entities::Lights::DirectionalLight* Clone() const { return new className(*this); }