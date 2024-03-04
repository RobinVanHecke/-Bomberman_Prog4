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

		void SetDeleted(const bool deleted) { m_Deleted = deleted; }
		bool GetDeleted() const { return m_Deleted; }

		

	protected:
		explicit BaseComponent(GameObject* gameObject) : m_pOwner(gameObject) {}
		GameObject* GetOwner() const { return m_pOwner; }

	private:
		bool m_Deleted{ false };

		GameObject* m_pOwner{ nullptr };
	};
}