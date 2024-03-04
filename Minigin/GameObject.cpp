#include "GameObject.h"

#include "RenderComponent.h"
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

	// delete Components
	std::erase_if(m_pComponents, [&](const std::shared_ptr<GameObject>& object) {return object->GetDeleted(); });
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_pComponents)
	{
		component.second->Render();
	}
}