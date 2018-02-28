#pragma once

#include "Entity.h"
#include "..\Managers\EUID.h"

#include <MathsLib\Containers\vec3.h>
#include <MathsLib\Containers\mat4.h>

using Maths::Containers::vec3;
using Maths::Containers::mat4;

namespace Entities {

	class GE_API Camera : public Entity
	{
	public:
		Camera(const std::string& EUID = Managers::NextCameraEUID());

		virtual Camera* Clone() const;
		void Start() override { }
		void Update() override { }

		void SetPosition(const vec3<float>& pos);
		void SetFront(const vec3<float>& focus);
		void SetUp(const vec3<float>& up);
		void SetFOV(float value);
		void SetNear(float value);
		void SetFar(float value);

		void IncrementPosition(const vec3<float>& amount);
		void DecrementPosition(const vec3<float>& amount);

		const vec3<float>& GetPosition() const;
		const vec3<float>& GetFront() const;
		const vec3<float>& GetUp() const;
		float GetFOV() const;
		float GetNear() const;
		float GetFar() const;
		const mat4<float>& GetViewMatrix();
		const mat4<float>& GetPerspectiveMatrix();
	private:
		vec3<float> m_Position;
		vec3<float> m_Front;
		vec3<float> m_Up;
		mat4<float> m_ViewMatrix;
		mat4<float> m_PerspectiveMatrix;

		float m_FOV;
		float m_Near;
		float m_Far;
	};

}

#define CAMERA_CLONE_METHOD(className) virtual Entities::Camera* Clone() const { return new className(*this); }