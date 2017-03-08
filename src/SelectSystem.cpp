#include "SelectSystem.h"
#include "SelectComponent.h"
#include "CommandQueueComponent.h"
#include "TypeComponent.h"
#include "MenuEvents.h"

SelectSystem::SelectSystem()
{
}

void SelectSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	// iterate over SelectionComponent
	entities.each<SelectComponent, CommandQueueComponent>([this, &events](Entity & entity, SelectComponent & select, CommandQueueComponent & queue)
	{
		UserCommand command;
		if (queue.getCommand(command))
		{
			switch (command)
			{
			case LEFT:
				break;
			case RIGHT:
				break;
			case UP:
				previousItem(select, events);
				break;
			case DOWN:
				nextItem(select, events);
				break;
			case USE:
				useItem(select, events);
				break;
			default:
				break;
			}
		}
	});
}

void SelectSystem::nextItem(SelectComponent & select, EventManager & events)
{
	if (select.m_selected == select.m_entityList.end())
	{
		select.m_selected = select.m_entityList.begin();
	}
	else
	{
		select.m_selected++;
	}

	events.emit<SelectEvent>(select.m_selected);
}

void SelectSystem::previousItem(SelectComponent & select, EventManager & events)
{
	if (select.m_selected == select.m_entityList.begin())
	{
		select.m_selected = std::prev(select.m_entityList.end());
	}
	else
	{
		select.m_selected--;
	}

	events.emit<SelectEvent>(select.m_selected);
}

void SelectSystem::useItem(SelectComponent & select, EventManager & events)
{
	auto type = select.m_selected->component<TypeComponent<MenuItem>>();
	// throw use event
	events.emit<UseEvent>(type->type);
}