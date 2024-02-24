#include "TextureComponent.h"

#include "ResourceManager.h"
#include "Texture2D.h"

void dae::TextureComponent::SetTexture(const std::shared_ptr<dae::Texture2D>& texture)
{
	m_pTexture = texture;
}

void dae::TextureComponent::SetTexture(const std::string& filename)
{
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}