#include "TextComponent.h"

#include <SDL_pixels.h>
#include <SDL_ttf.h>
#include <stdexcept>

#include "Renderer.h"
#include "Font.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "TextureComponent.h"
#include "Texture2D.h"

dae::TextComponent::TextComponent(GameObject* gameObject) : BaseComponent(gameObject)
{
	// TextComponent cannot exist without a TextureComponent
	gameObject->AddComponent<TextureComponent>();

	// default font, because a text always needs a font to function
	m_pFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
}

void dae::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}

void dae::TextComponent::SetFont(const std::shared_ptr<Font>& pFont)
{
	m_pFont = pFont;
}

void dae::TextComponent::Update(float /*deltaT*/)
{
	if (m_NeedsUpdate)
	{
		constexpr SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_pFont->GetFont(), m_Text.c_str(), color);

		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}

		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);

		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}

		SDL_FreeSurface(surf);

		if (!m_Text.empty())
		{
			GetOwner()->GetComponent<TextureComponent>()->SetTexture(std::make_unique<Texture2D>(texture));
		}

		m_NeedsUpdate = false;
	}
}