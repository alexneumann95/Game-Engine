#pragma once

#include "Entity.h"
#include "..\Managers\EUID.h"
#include "..\Maths\vec3.h"
#include "..\Maths\mat4.h"

using namespace Maths;

namespace Entities {

	class GE_API Camera : public Entity
	{
	public:
		Camera(const std::string& EUID = Managers::NextCameraEUID());

		virtual Camera* Clone() const;
		void Start() override { }
		void Update() override { }

		void SetPosition(const vec3& pos);
		void SetDirection(const vec3& direction);
		void SetUp(const vec3& up);
		void SetFOV(float value);
		void SetNear(float value);
		void SetFar(float value);

		void IncrementPosition(const vec3& amount);
		void DecrementPosition(const vec3& amount);

		const vec3& GetPosition() const;
		const vec3& GetDirection() const;
		const vec3& GetUp() const;
		float GetFOV() const;
		float GetNear() const;
		float GetFar() const;
		const mat4& GetViewMatrix();
		const mat4& GetPerspectiveMatrix();
	private:
		vec3 m_Position;
		vec3 m_Direction;
		vec3 m_Up;
		mat4 m_ViewMatrix;
		mat4 m_PerspectiveMatrix;

		float m_FOV;
		float m_Near;
		float m_Far;
	};

}

#define CAMERA_CLONE_METHOD(className) virtual Entities::Camera* Clone() const { return new className(*this); }