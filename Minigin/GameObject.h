#pragma once
#include <memory>
#include <unordered_map>
#include <typeindex>

#include "BaseComponent.h"

namespace dae
{
	class Texture2D;

	class GameObject final
	{
	public:
		GameObject();
		~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update(float deltaT);
		void Render() const;

		void SetDeleted(const bool deleted) { m_Deleted = deleted; }
		bool GetDeleted() const { return m_Deleted; }

		template<typename Comp> Comp* AddComponent();
		template<typename Comp> Comp* GetComponent() const;
		template<typename Comp> void RemoveComponent();

	private:
		bool m_Deleted{ false };

		std::unordered_map<std::type_index, std::unique_ptr<BaseComponent>> m_pComponents;
	};

	template <typename Comp>
	Comp* GameObject::AddComponent()
	{
		static_assert(std::is_base_of_v<BaseComponent, Comp>, "Component must derive from BaseComponent");

		m_pComponents.emplace(typeid(Comp), std::make_unique<Comp>(this));

		return dynamic_cast<Comp*>(m_pComponents.at(typeid(Comp)).get());
	}

	template <typename Comp>
	Comp* GameObject::GetComponent() const
	{
		static_assert(std::is_base_of_v<BaseComponent, Comp>, "Component must derive from BaseComponent");

		if (const auto it = m_pComponents.find(typeid(Comp)); it != m_pComponents.end())
			return dynamic_cast<Comp*>(it->second.get());

		return nullptr;
	}

	template <typename Comp>
	void GameObject::RemoveComponent()
	{
		if (const auto it = m_pComponents.find(typeid(Comp)); it != m_pComponents.end())
			m_pComponents.erase(it);
	}
}