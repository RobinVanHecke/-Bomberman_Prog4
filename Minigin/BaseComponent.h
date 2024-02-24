#pragma once

namespace dae
{
	class GameObject;

	class BaseComponent
	{
	public:
		virtual void Update(float /*deltaT*/) {}
		virtual void Render() const {}

		BaseComponent() = default;
		explicit BaseComponent(GameObject* gameObject) : m_pOwner(gameObject) {}
		virtual ~BaseComponent() = default;

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

	protected:
		GameObject* GetOwner() const { return m_pOwner; }

	private:
		GameObject* m_pOwner{ nullptr };

	};
}
