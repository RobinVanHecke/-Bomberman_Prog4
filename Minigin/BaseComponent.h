#pragma once

namespace dae
{
	class GameObject;

	class BaseComponent
	{
	public:
		virtual ~BaseComponent() = default;

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		virtual void Update(float /*deltaT*/) {}
		virtual void Render() const {}

		

	protected:
		explicit BaseComponent(GameObject* gameObject) : m_pOwner(gameObject) {}
		GameObject* GetOwner() const { return m_pOwner; }

	private:
		GameObject* m_pOwner{ nullptr };
	};
}