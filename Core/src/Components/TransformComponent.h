#pragma once

#include "Component.h"
#include "..\Maths\vec3.h"
#include "..\Maths\mat4.h"

using namespace Maths;

namespace Components {

	enum class TransformationOrder
	{
		Translation_Scale_Rotation = 0,
		Translation_Rotation_Scale = 1
	};

	class GE_API TransformComponent final : public Component
	{
	public:
		TransformComponent(Entities::GameObject* const pGameObject);

		void Init() override;

		void SetPosition(vec3 pos);
		void SetScale(vec3 scale);
		void SetRotation(vec3 rotation);
		void SetTransOrder(TransformationOrder order);

		const vec3& GetPosition() const;
		const vec3& GetScale() const;
		const vec3& GetRotation() const;
		TransformationOrder GetTransOrder() const;
		const mat4& GetModelMatrix();
	private:
		void CalculateModelMatrix();
	private:
		vec3 m_Position = vec3(0.0f, 0.0f, 0.0f);
		vec3 m_Scale = vec3(1.0f, 1.0f, 1.0f);
		vec3 m_Rotation = vec3(0.0f, 0.0f, 0.0f);
		TransformationOrder m_TransOrder = TransformationOrder::Translation_Scale_Rotation;	
		mat4 m_ModelMatrix;
	};

}