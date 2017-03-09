#include "SelectComponent.h"

SelectComponent::SelectComponent(std::vector<Entity>& entityList, double selectDelay)
	:
	entityList(entityList),
	selected(this->entityList.begin()),
	selectDelay(selectDelay),
	delayTimer(0.0)
{
	assert(!entityList.empty());	
}
