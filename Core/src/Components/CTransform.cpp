#include "CTransform.h"

namespace Components {

	CTransform::CTransform(Entities::GameObject* const pGameObject) : Component(pGameObject, ComponentType::TRANSFORM)
	{

	}

	void CTransform::Init()
	{
		m_ModelMatrix = mat4<float>::Identity();
	}

	void CTransform::SetPosition(const vec3<float>& pos)
	{
		m_Position = pos;
	}

	void CTransform::SetScale(const vec3<float>& scale)
	{
		m_Scale = scale;
	}

	void CTransform::SetRotation(const vec3<float>& rotation)
	{
		m_Rotation = rotation;
	}

	void CTransform::SetTransOrder(TransformationOrder order)
	{
		m_TransOrder = order;
	}

	const vec3<float>& CTransform::GetPosition() const
	{
		return m_Position;
	}

	const vec3<float>& CTransform::GetScale() const
	{
		return m_Scale;
	}

	const vec3<float>& CTransform::GetRotation() const
	{
		return m_Rotation;
	}

	TransformationOrder CTransform::GetTransOrder() const
	{
		return m_TransOrder;
	}

	const mat4<float>& CTransform::GetModelMatrix()
	{
		CalculateModelMatrix();

		return m_ModelMatrix;
	}

	void CTransform::CalculateModelMatrix()
	{
		mat4<float> translationMatrix = mat4<float>::Translation(m_Position);
		mat4<float> scaleMatrix = mat4<float>::Scale(m_Scale);
		mat4<float> rotationMatrix = mat4<float>::Rotation(m_Rotation.X, vec3<float>(1.0f, 0.0f, 0.0f)) * mat4<float>::Rotation(m_Rotation.Y, vec3<float>(0.0f, 1.0f, 0.0f))
								* mat4<float>::Rotation(m_Rotation.Z, vec3<float>(0.0f, 0.0f, 1.0f));
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