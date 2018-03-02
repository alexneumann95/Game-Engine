#include "Camera.h"
#include "..\App\GameWindow.h"

namespace Entities {

	Camera::Camera() : Entity(Managers::NextCameraEUID(), EntityType::CAMERA), m_Position(vec3<float>(0.0f, 0.0f, 2.0f)), m_Front(vec3<float>(0.0f, 0.0f, -1.0f)),
		m_Up(vec3<float>(0.0f, 1.0f, 0.0f)), m_FOV(90.0f), m_Near(0.1f), m_Far(100.0f)
	{
		
	}

	Camera* Camera::Clone() const
	{
		return new Camera(*this);
	}

	void Camera::SetPosition(const vec3<float>& pos)
	{
		m_Position = pos;
	}

	void Camera::SetFront(const vec3<float>& focus)
	{
		m_Front = focus;
	}

	void Camera::SetUp(const vec3<float>& up)
	{
		m_Up = up;
	}

	void Camera::SetFOV(float value)
	{
		if (value > 0.0f && value < 180.0f)
			m_FOV = value;
	}

	void Camera::SetNear(float value)
	{
		if (value > 0.0f)
			m_Near = value;
	}

	void Camera::SetFar(float value)
	{
		if (value > 0.0f)
			m_Far = value;
	}

	void Camera::IncrementPosition(const vec3<float>& amount)
	{
		m_Position += amount;
	}

	void Camera::DecrementPosition(const vec3<float>& amount)
	{
		m_Position -= amount;
	}

	const vec3<float>& Camera::GetPosition() const
	{
		return m_Position;
	}

	const vec3<float>& Camera::GetFront() const
	{
		return m_Front;
	}

	const vec3<float>& Camera::GetUp() const
	{
		return m_Up;
	}

	float Camera::GetFOV() const
	{
		return m_FOV;
	}

	float Camera::GetNear() const
	{
		return m_Near;
	}

	float Camera::GetFar() const
	{
		return m_Far;
	}

	const mat4<float>& Camera::GetViewMatrix()
	{
		m_ViewMatrix = mat4<float>::LookAt(m_Position, m_Front + m_Position, m_Up);
		return m_ViewMatrix;
	}

	const mat4<float>& Camera::GetPerspectiveMatrix()
	{
		float width = (float)GAME_WINDOW->GetWidth();
		float height = (float)GAME_WINDOW->GetHeight();

		m_PerspectiveMatrix = mat4<float>::Perspective(m_FOV, width / height, m_Near, m_Far);
		return m_PerspectiveMatrix;
	}

}