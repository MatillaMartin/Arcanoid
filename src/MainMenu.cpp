#include "MainMenu.h"

#include "MenuEvents.h"
#include "Textures.h"
#include "InputSystem.h"
#include "SelectSystem.h"

#include "TypeComponent.h"
#include "SpriteComponent.h"
#include "KeyboardInputComponent.h"
#include "CommandQueueComponent.h"
#include "PositionComponent.h"

MainMenu::MainMenu(const Params & params, const Visuals & visuals, const Callbacks & callbacks)
	:
	m_params(params),
	m_visuals(visuals),
	m_callbacks(callbacks)
{
	setupEntityX();
	setupMenu();
}

void MainMenu::update(double delta)
{
	systems.update<InputSystem>(delta);
	systems.update<SelectSystem>(delta);
}

void MainMenu::draw(Renderer * renderer)
{
	// draw all sprites
	entities.each<PositionComponent, SpriteComponent>(
		[renderer](Entity entity, PositionComponent & position, SpriteComponent & visual)
	{
		renderer->drawSprite(position.position, position.size, visual.texture);
	});
}

void MainMenu::input(char input)
{
	systems.system<InputSystem>()->onInput(input);
}

void MainMenu::setupEntityX()
{
	systems.add<InputSystem>();
	systems.add<SelectSystem>();

	systems.configure();

	this->events.subscribe<UseMenuEvent>(*this);
	this->events.subscribe<SelectMenuEvent>(*this);
}

void MainMenu::setupMenu()
{
	std::vector<Entity> menuEntities;

	// compute regions
	ofRectangle playRegion = m_visuals.menuRegion.map(m_visuals.playRegion);
	ofRectangle creditsRegion = m_visuals.menuRegion.map(m_visuals.creditsRegion);
	ofRectangle exitRegion = m_visuals.menuRegion.map(m_visuals.exitRegion);

	// setup play
	Entity play = entities.create();
	play.assign<TypeComponent<MenuItem>>(MenuItem::MENU_PLAY);
	play.assign<SpriteComponent>(TextureId::PLAY_SEL); // start with play selected
	play.assign<PositionComponent>(glm::vec2(playRegion.getX(), playRegion.getY()), glm::vec2(playRegion.getWidth(), playRegion.getHeight()));
	menuEntities.push_back(play);
	
	// setup credits
	Entity credits = entities.create();
	credits.assign<TypeComponent<MenuItem>>(MenuItem::MENU_CREDITS);
	credits.assign<SpriteComponent>(TextureId::CREDITS);
	credits.assign<PositionComponent>(glm::vec2(creditsRegion.getX(), creditsRegion.getY()), glm::vec2(creditsRegion.getWidth(), creditsRegion.getHeight()));
	menuEntities.push_back(credits);

	// setup exit
	Entity quit = entities.create();
	quit.assign<TypeComponent<MenuItem>>(MenuItem::MENU_EXIT);
	quit.assign<SpriteComponent>(TextureId::EXIT);
	quit.assign<PositionComponent>(glm::vec2(exitRegion.getX(), exitRegion.getY()), glm::vec2(exitRegion.getWidth(), exitRegion.getHeight()));
	menuEntities.push_back(quit);

	// setup selector
	Entity selector = entities.create();
	selector.assign<SelectComponent>(menuEntities, m_params.selectDelay);
	selector.assign<KeyboardInputComponent>('a', 'd', 'w', 's', ' ');
	selector.assign<CommandQueueComponent>();
}

void MainMenu::receive(const UseMenuEvent & e)
{
	switch (e.item)
	{
	case MenuItem::MENU_NONE:
		// nothing here, edge case that there is nothing selected
		break;
	case MenuItem::MENU_PLAY:
		if (m_callbacks.onPlay)
		{
			m_callbacks.onPlay();
		}
		else
		{
			ofLogError("MainMenu") << "onPlay callback not set";
		}
		break;
	case MenuItem::MENU_CREDITS:
		if (m_callbacks.onCredits)
		{
			m_callbacks.onCredits();
		}
		else
		{
			ofLogError("MainMenu") << "onCredits callback not set";
		}
		break;
	case MenuItem::MENU_EXIT:
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

void MainMenu::receive(const SelectMenuEvent & e)
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