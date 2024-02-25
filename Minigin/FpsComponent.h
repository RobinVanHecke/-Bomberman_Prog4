#pragma once
#include <string>

#include "BaseComponent.h"

namespace dae
{
	class FpsComponent final : public BaseComponent
	{
	public:
		FpsComponent(GameObject* gameObject) : BaseComponent(gameObject) {}

		void Update(float deltaT) override;
		float GetFps() const { return m_Fps; }

	private:
		float m_Fps{ 1 };
		std::string m_FpsString;
	};
}
