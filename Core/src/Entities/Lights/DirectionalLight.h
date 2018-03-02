#pragma once

#include "..\Entity.h"
#include "..\..\Managers\EUID.h"

#include <MathsLib\Containers\vec3.h>
#include <MathsLib\Containers\vec4.h>

using Maths::Containers::vec3;

namespace Entities::Lights {

	class GE_API DirectionalLight : public Entity
	{
	public:
		DirectionalLight(const vec3<float>& direction = vec3<float>(0.0f, -1.0f, 0.0f), const vec3<float>& ambient = vec3<float>(1.0f, 1.0f, 1.0f), 
			const vec3<float>& diffuse = vec3<float>(1.0f, 1.0f, 1.0f), const vec3<float>& specular = vec3<float>(1.0f, 1.0f, 1.0f));

		virtual DirectionalLight* Clone() const;

		void Start() override { }
		void Update() override { }

		void SetDirection(const vec3<float>& direction);
		void SetAmbient(const vec3<float>& value);
		void SetDiffuse(const vec3<float>& value);
		void SetSpecular(const vec3<float>& value);

		const vec3<float>& GetDirection() const;
		const vec3<float>& GetAmbient() const;
		const vec3<float>& GetDiffuse() const;
		const vec3<float>& GetSpecular() const;
	private:
		vec3<float> m_Direction; // Direction from "light position" to scene
		vec3<float> m_Ambient;
		vec3<float> m_Diffuse;
		vec3<float> m_Specular;
	};

}

#define DIRECTIONAL_LIGHT_CLONE_METHOD(className) virtual Entities::Lights::DirectionalLight* Clone() const { return new className(*this); }