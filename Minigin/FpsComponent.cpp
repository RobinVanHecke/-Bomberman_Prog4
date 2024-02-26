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
	m_OldFps = m_Fps;

	m_Fps = 1 / deltaT;

	m_Fps = floor(m_Fps);

	m_FpsString = std::to_string(static_cast<int>(m_Fps));
	
	if (m_Fps >= m_OldFps + 0.1f || m_Fps <= m_OldFps - 0.1f)
	{
		m_pTextComponent->SetText(m_FpsString);
	}
}