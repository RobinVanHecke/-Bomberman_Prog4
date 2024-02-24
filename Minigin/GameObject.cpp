#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject()
{
	m_Components.erase(m_Components.begin(), m_Components.end());
	m_Components.clear();
}

void dae::GameObject::Update(const float deltaT)
{
	for (const auto& component : m_Components)
	{
		component.second->Update(deltaT);
	}
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_Components)
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
