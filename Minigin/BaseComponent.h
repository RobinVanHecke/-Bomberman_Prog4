#pragma once

namespace dae
{
	class GameObject;

	class BaseComponent
	{
	public:
		BaseComponent() = default;
		virtual ~BaseComponent() = default;
		BaseComponent(const GameObject& other) = delete;
		BaseComponent(GameObject&& other) = delete;
		BaseComponent& operator=(const GameObject& other) = delete;
		BaseComponent& operator=(GameObject&& other) = delete;

		virtual void Update(float /*deltaT*/) {}
		virtual void Render() const {}

	private:
	};
}
