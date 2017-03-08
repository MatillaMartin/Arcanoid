#include "MainMenu.h"

#include "MenuEvents.h"
#include "Textures.h"
#include "InputSystem.h"
#include "SelectSystem.h"

#include "TypeComponent.h"
#include "SpriteComponent.h"
#include "KeyboardInputComponent.h"

MainMenu::MainMenu(const Visuals & visuals, const Callbacks & callbacks)
	:
	m_visuals(visuals),
	m_playEventHandler(callbacks.onPlay),
	m_creditsEventHandler(callbacks.onCredits),
	m_exitEventHandler(callbacks.onExit)
{
	setupEntityX();
	setupMenu();
}

void MainMenu::update(float delta)
{
	systems.update<InputSystem>(delta);
	systems.update<SelectSystem>(delta);
}

void MainMenu::draw(Renderer * renderer)
{

}

void MainMenu::setupEntityX()
{
	systems.add<InputSystem>();
	systems.add<SelectSystem>();

	systems.configure();

	this->events.subscribe<UseEvent>(this);
	this->events.subscribe<SelectEvent>(this);
}

void MainMenu::setupMenu()
{
	std::vector<Entity> menuEntities;

	// setup play
	Entity play = entities.create();
	play.assign<TypeComponent<MenuItem>>(MenuItem::MENU_PLAY);
	play.assign<SpriteComponent>(TextureId::PLAY);
	menuEntities.push_back(play);
	
	// setup credits
	Entity credits = entities.create();
	play.assign<TypeComponent<MenuItem>>(MenuItem::MENU_CREDITS);
	play.assign<SpriteComponent>(TextureId::CREDITS);
	menuEntities.push_back(credits);

	// setup exit
	Entity quit = entities.create();
	play.assign<TypeComponent<MenuItem>>(MenuItem::MENU_EXIT);
	play.assign<SpriteComponent>(TextureId::EXIT);
	menuEntities.push_back(quit);

	// setup selector
	Entity selector = entities.create();
	selector.assign<SelectComponent>(menuEntities);
	selector.assign<KeyboardInputComponent>('a', 'd', 'w', 's', ' ');
}

void MainMenu::receive(const UseEvent & e)
{
	switch (e.item)
	{
	case MENU_NONE:
		// nothing here, edge case that there is nothing selected
		break;
	case MENU_PLAY:
		if (m_callbacks.onPlay)
		{
			m_callbacks.onPlay();
		}
		else
		{
			ofLogError("MainMenu") << "onPlay callback not set";
		}
		break;
	case MENU_CREDITS:
		if (m_callbacks.onCredits)
		{
			m_callbacks.onCredits();
		}
		else
		{
			ofLogError("MainMenu") << "onCredits callback not set";
		}
		break;
	case MENU_EXIT:
		if (m_callbacks.onExit)
		{
			m_callbacks.onExit();
		}
		else
		{
			ofLogError("MainMenu") << "onExit callback not set";
		}
		break;
	default:
		break;
	}
}

void MainMenu::receive(const SelectEvent & e)
{
	// couple selection events to visual effects
	onSelectVisualBehaviour(e.entity);

	// couple selection events to sound effects?
}

void MainMenu::onSelectVisualBehaviour(Entity selected)
{
	auto sprite = selected.component<SpriteComponent>();
	auto item = selected.component<TypeComponent<MenuItem>>();
	if (sprite && item)
	{
		if (m_visuals.menuItemMap.find(item->type) != m_visuals.menuItemMap.end())
		{
			// set all entites to not selected sprite
			entities.each<SpriteComponent, TypeComponent<MenuItem>>([this](Entity & e, SpriteComponent & sprite, TypeComponent<MenuItem> & item)
			{
				sprite.texture = m_visuals.menuItemMap.at(item.type).first;
			});

			// set selected entity to selected sprite
			sprite->texture = m_visuals.menuItemMap.at(item->type).second;
		}
	}
	else
	{
		ofLogError("MainMenu") << "Selected does not have a SpriteComponent or TypeComponent<MenuItem>";
	}
}