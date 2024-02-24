#pragma once
#include <memory>
#include "Transform.h"

namespace dae
{
	class Texture2D;

	class GameObject final
	{
	public:
		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		virtual void Update(float deltaT);
		virtual void Render() const;

	private:
	};
}
