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
		DirectionalLight(const std::string& EUID = Managers::NextDirectionalLightEUID());
		DirectionalLight(const vec3<float>& direction, const vec3<float>& colour, const std::string& EUID = Managers::NextDirectionalLightEUID());

		virtual DirectionalLight* Clone() const;

		void Start() override { }
		void Update() override { }

		void SetDirection(const vec3<float>& direction);
		void SetColour(const vec3<float>& colour);

		const vec3<float>& GetDirection() const;
		const vec3<float>& GetColour() const;
	private:
		vec3<float> m_Direction = vec3<float>(0.0f, -1.0f, 0.0f); // Direction from "light position" to scene
		vec3<float> m_Colour = vec3<float>(1.0f, 1.0f, 1.0f);
	};

}

#define DIRECTIONAL_LIGHT_CLONE_METHOD(className) virtual Entities::Lights::DirectionalLight* Clone() const { return new className(*this); }