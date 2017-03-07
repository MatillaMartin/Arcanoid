#include "MainMenu.h"

#include "MenuEvents.h"

#include "InputSystem.h"
#include "SelectSystem.h"

MainMenu::MainMenu(std::function<void()> onPlay)
	:
	m_playEventHandler(onPlay)
{

}

void MainMenu::update()
{

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
