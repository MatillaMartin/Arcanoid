#include "MainMenu.h"

#include "MenuEvents.h"
#include "Textures.h"
#include "InputSystem.h"
#include "SelectSystem.h"

#include "UseComponent.h"
#include "SpriteComponent.h"

MainMenu::MainMenu(std::function<void()> onPlay)
	:
	m_playEventHandler(onPlay)
{
	setupEntityX();
	setupMenu();
}

void MainMenu::update(float delta)
{
	systems.update<InputSystem>(delta);
	systems.update<SelectSystem>(delta);
}

void MainMenu::draw()
{

}

void MainMenu::setupEntityX()
{
	systems.add<InputSystem>();
	systems.add<SelectSystem>();
	systems.configure();

	this->events.subscribe<PlayEvent>(m_playEventHandler);
}

void MainMenu::setupMenu()
{
	std::vector<Entity> menuEntities;

	// setup play
	Entity play = entities.create();
	play.assign<UseComponent>(MenuItem::MENU_PLAY);
	play.assign<SpriteComponent>(TextureId::PLAY);
	menuEntities.push_back(play);
	
	// setup credits
	Entity credits = entities.create();
	credits.assign<UseComponent>(MenuItem::MENU_CREDITS);
	play.assign<SpriteComponent>(TextureId::CREDITS);
	menuEntities.push_back(credits);

	// setup exit
	Entity quit = entities.create();
	quit.assign<UseComponent>(MenuItem::MENU_EXIT);
	play.assign<SpriteComponent>(TextureId::EXIT);
	menuEntities.push_back(quit);

	// setup selector
	Entity selector = entities.create();
	selector.assign<SelectComponent>(menuEntities);
}