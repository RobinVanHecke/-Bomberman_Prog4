#include "FpsComponent.h"

#include "GameObject.h"
#include "TextComponent.h"


dae::FpsComponent::FpsComponent(GameObject* gameObject) : BaseComponent(gameObject)
{
	//FpsComponent cannot exist without a TextComponent
	gameObject->AddComponent<TextComponent>();

	m_pTextComponent = GetOwner()->GetComponent<TextComponent>();
}

void dae::FpsComponent::Update(const float deltaT)
{
	m_Fps = 1 / deltaT;

	m_Fps = floor(m_Fps);

	m_FpsString = std::to_string(static_cast<int>(m_Fps));

	m_pTextComponent->SetText(m_FpsString);
}