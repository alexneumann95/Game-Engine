#pragma once

#include "Component.h"

#include <MathsLib\Containers\vec3.h>
#include <MathsLib\Containers\vec4.h>
#include <MathsLib\Containers\mat4.h>

using Maths::Containers::vec3;
using Maths::Containers::vec4;
using Maths::Containers::mat4;

namespace Components {

	enum class TransformationOrder
	{
		Translation_Scale_Rotation = 0,
		Translation_Rotation_Scale = 1
	};

	class GE_API CTransform final : public Component
	{
	public:
		CTransform(Entities::GameObject* const pGameObject);

		void Init() override;

		void SetPosition(const vec3<float>& pos);
		void SetScale(const vec3<float>& scale);
		void SetRotation(const vec3<float>& rotation);
		void SetTransOrder(TransformationOrder order);

		const vec3<float>& GetPosition() const;
		const vec3<float>& GetScale() const;
		const vec3<float>& GetRotation() const;
		TransformationOrder GetTransOrder() const;
		const mat4<float>& GetModelMatrix();
	private:
		void CalculateModelMatrix();
	private:
		vec3<float> m_Position = vec3<float>(0.0f, 0.0f, 0.0f);
		vec3<float> m_Scale = vec3<float>(1.0f, 1.0f, 1.0f);
		vec3<float> m_Rotation = vec3<float>(0.0f, 0.0f, 0.0f);
		TransformationOrder m_TransOrder = TransformationOrder::Translation_Scale_Rotation;	
		mat4<float> m_ModelMatrix;
	};

}