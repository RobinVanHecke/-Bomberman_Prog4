#include "GameObject.h"

#include "TransformComponent.h"

dae::GameObject::GameObject()
{
	// GameObject always has a Transform Component
	AddComponent<TransformComponent>()->SetPos(0.f, 0.f);
}

void dae::GameObject::Update(const float deltaT)
{
	for (auto& component : m_pComponents)
	{
		component.second->Update(deltaT);
	}
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_pComponents)
	{
		component.second->Render();
	}
}

void dae::GameObject::SetDeleted(const bool deleted)
{
	m_Deleted = deleted;
}

bool dae::GameObject::GetDeleted() const
{
	return m_Deleted;
}