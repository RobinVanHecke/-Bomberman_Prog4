#pragma once
#include <memory>
#include <string>

#include "BaseComponent.h"

namespace dae
{
	class Font;
	class Texture2D;

	class TextComponent final : public BaseComponent
	{
	public:
		explicit TextComponent(GameObject* gameObject) : BaseComponent(gameObject) {}

		void SetText(const std::string& text);
		void SetText(float floatToText);
		void SetFont(const std::shared_ptr<Font>& font);

		void Update(float /*deltaT*/) override;


	private:
		bool m_NeedsUpdate{ false };

		std::string m_Text;
		std::shared_ptr<Font> m_Font;
	};
}
