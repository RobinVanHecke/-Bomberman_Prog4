#pragma once
#include <memory>
#include <string>

#include "BaseComponent.h"

namespace dae
{
	class Texture2D;

	class TextureComponent final : public BaseComponent
	{
	public:
		TextureComponent(GameObject* gameObject) : BaseComponent(gameObject) {}

		void SetTexture(const std::shared_ptr<Texture2D>& texture);
		void SetTexture(const std::string& filename);
		std::shared_ptr<Texture2D> GetTexture() const { return m_pTexture; }

	private:
		std::shared_ptr<Texture2D> m_pTexture;
	};
}
