#include "TransformComponent.h"

namespace Components {

	TransformComponent::TransformComponent(Entities::GameObject* const pGameObject) : Component(pGameObject)
	{

	}

	void TransformComponent::Init()
	{
		m_ModelMatrix = mat4::Identity();
	}

	void TransformComponent::SetPosition(vec3 pos)
	{
		m_Position = pos;
	}

	void TransformComponent::SetScale(vec3 scale)
	{
		m_Scale = scale;
	}

	void TransformComponent::SetRotation(vec3 rotation)
	{
		m_Rotation = rotation;
	}

	void TransformComponent::SetTransOrder(TransformationOrder order)
	{
		m_TransOrder = order;
	}

	const vec3& TransformComponent::GetPosition() const
	{
		return m_Position;
	}

	const vec3& TransformComponent::GetScale() const
	{
		return m_Scale;
	}

	const vec3& TransformComponent::GetRotation() const
	{
		return m_Rotation;
	}

	TransformationOrder TransformComponent::GetTransOrder() const
	{
		return m_TransOrder;
	}

	const mat4& TransformComponent::GetModelMatrix()
	{
		CalculateModelMatrix();

		return m_ModelMatrix;
	}

	void TransformComponent::CalculateModelMatrix()
	{
		mat4 translationMatrix = mat4::Translation(m_Position);
		mat4 scaleMatrix = mat4::Scale(m_Scale);
		mat4 rotationMatrix = mat4::Rotation(m_Rotation.X, vec3(1.0f, 0.0f, 0.0f)) * mat4::Rotation(m_Rotation.Y, vec3(0.0f, 1.0f, 0.0f))
								* mat4::Rotation(m_Rotation.Z, vec3(0.0f, 0.0f, 1.0f));
		switch (m_TransOrder)
		{
		case TransformationOrder::Translation_Scale_Rotation:
			m_ModelMatrix = translationMatrix * scaleMatrix * rotationMatrix;
			break;
		case TransformationOrder::Translation_Rotation_Scale:
			m_ModelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
			break;
		}
	}
}