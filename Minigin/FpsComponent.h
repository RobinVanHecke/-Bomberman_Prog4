#pragma once
#include <string>

#include "BaseComponent.h"


namespace dae
{
	class TextComponent;

	class FpsComponent final : public BaseComponent
	{
	public:
		explicit FpsComponent(GameObject* gameObject);

		void Update(float deltaT) override;
		float GetFps() const { return m_Fps; }

	private:
		float m_Fps{ 0 };
		std::string m_FpsString;
		TextComponent* m_pTextComponent = nullptr;
	};
}
