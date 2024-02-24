#include "TransformComponent.h"

void dae::TransformComponent::SetPos(const glm::vec3 newPos)
{
	m_Position = newPos;
}

void dae::TransformComponent::SetPos(const float newX, const float newY, const float newZ)
{
	m_Position.x = newX;
	m_Position.y = newY;
	m_Position.z = newZ;
}

glm::vec3 dae::TransformComponent::GetPos() const
{
	return m_Position;
}
