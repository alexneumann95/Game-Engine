#pragma once

#include "..\..\Common.h"
#include "..\Entity.h"
#include "..\..\Managers\EUID.h"

#include <MathsLib\Containers\vec3.h>

using Maths::Containers::vec3;

namespace Entities::Lights {

	class GE_API Light : public Entity
	{
	public:
		Light(const std::string& EUID, EntityType type, const vec3<float>& ambient, const vec3<float>& diffuse, const vec3<float>& specular);

		void Start() override = 0;
		void Update() override = 0;

		void SetAmbient(const vec3<float>& value);
		void SetDiffuse(const vec3<float>& value);
		void SetSpecular(const vec3<float>& value);

		const vec3<float>& GetAmbient() const;
		const vec3<float>& GetDiffuse() const;
		const vec3<float>& GetSpecular() const;
	private:
		vec3<float> m_Ambient;
		vec3<float> m_Diffuse;
		vec3<float> m_Specular;
	};

}