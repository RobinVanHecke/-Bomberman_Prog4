#pragma once
#include <string>

#include "BaseComponent.h"


namespace dae
{
	class TextComponent;

	class FpsComponent final : public BaseComponent
	{
	public:
		FpsComponent(GameObject* gameObject);

		void Update(float deltaT) override;
		float GetFps() const { return m_Fps; }

	private:
		float m_Fps{ 1 };
		std::string m_FpsString;
		TextComponent* m_pTextComponent = nullptr;
	};
}
