#pragma once
#include <glm/vec3.hpp>

#include "BaseComponent.h"

namespace dae
{
	class TransformComponent final : public BaseComponent
	{
	public:
		explicit TransformComponent(GameObject* gameObject) : BaseComponent(gameObject) {}

		void SetPos(glm::vec3 newPos);
		void SetPos(float newX, float newY, float newZ = 0.f);
		glm::vec3 GetPos() const;

	private:
		glm::vec3 m_Position{};
	};
}