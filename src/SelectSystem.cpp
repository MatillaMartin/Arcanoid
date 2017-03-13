#include "SelectSystem.h"
#include "SelectComponent.h"
#include "CommandQueueComponent.h"
#include "TypeComponent.h"
#include "MenuEvents.h"

SelectSystem::SelectSystem()
	:
	bContinuous(false)
{
}

void SelectSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	// iterate over SelectionComponent
	entities.each<SelectComponent, CommandQueueComponent>([this, &events, dt](Entity & entity, SelectComponent & select, CommandQueueComponent & queue)
	{
		// update selection delay
		select.delayTimer += dt;

		// get command if any
		UserCommand command;
		if (queue.getCommand(command))
		{
			// if there has not been a pause between commands check delay
			if (bContinuous)
			{
				// if its not time to use the command then return
				if (select.delayTimer < select.selectDelay)
				{
					// refresh the command queue list
					queue.clear();
					return;
				}
			}
			else
			{
				bContinuous = true;
			}

			// reset the timer and select
			select.delayTimer = 0.0;


			// proceed to apply command
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
		else
		{
			bContinuous = false;
		}
	});
}

void SelectSystem::nextItem(SelectComponent & select, EventManager & events)
{
	select.selected++;
	if (select.selected == select.entityList.end())
	{
		select.selected = select.entityList.begin();
	}

	events.emit<SelectMenuEvent>(*select.selected);
}

void SelectSystem::previousItem(SelectComponent & select, EventManager & events)
{
	if (select.selected == select.entityList.begin())
	{
		select.selected = std::prev(select.entityList.end());
	}
	else
	{
		select.selected--;
	}

	events.emit<SelectMenuEvent>(*select.selected);
}

void SelectSystem::useItem(SelectComponent & select, EventManager & events)
{
	auto type = select.selected->component<TypeComponent<MenuItem>>();
	// throw use event
	events.emit<UseMenuEvent>(type->type);
}