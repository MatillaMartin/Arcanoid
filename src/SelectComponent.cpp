#include "SelectComponent.h"

SelectComponent::SelectComponent(std::vector<Entity>& entityList)
	:
	m_selected(entityList.begin())
{
	assert(!m_entityList.empty());	
}
