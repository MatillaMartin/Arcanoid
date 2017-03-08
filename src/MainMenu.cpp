#include "MainMenu.h"

#include "MenuEvents.h"
#include "Textures.h"
#include "InputSystem.h"
#include "SelectSystem.h"

#include "TypeComponent.h"
#include "SpriteComponent.h"
#include "KeyboardInputComponent.h"
#include "PhysicsComponent.h"

MainMenu::MainMenu(const Visuals & visuals, const Callbacks & callbacks)
	:
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
	entities.each<PhysicsComponent, SpriteComponent>(
		[renderer](Entity entity, PhysicsComponent & physics, SpriteComponent & visual)
	{
		renderer->drawSprite(physics.position, physics.size, visual.texture);
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

	this->events.subscribe<UseEvent>(*this);
	this->events.subscribe<SelectEvent>(*this);
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
	play.assign<SpriteComponent>(TextureId::PLAY);
	play.assign<PhysicsComponent>(glm::vec2(playRegion.getX(), playRegion.getY()), glm::vec2(playRegion.getWidth(), playRegion.getHeight()));
	menuEntities.push_back(play);
	
	// setup credits
	Entity credits = entities.create();
	credits.assign<TypeComponent<MenuItem>>(MenuItem::MENU_CREDITS);
	credits.assign<SpriteComponent>(TextureId::CREDITS);
	credits.assign<PhysicsComponent>(glm::vec2(creditsRegion.getX(), creditsRegion.getY()), glm::vec2(creditsRegion.getWidth(), creditsRegion.getHeight()));
	menuEntities.push_back(credits);

	// setup exit
	Entity quit = entities.create();
	quit.assign<TypeComponent<MenuItem>>(MenuItem::MENU_EXIT);
	quit.assign<SpriteComponent>(TextureId::EXIT);
	quit.assign<PhysicsComponent>(glm::vec2(exitRegion.getX(), exitRegion.getY()), glm::vec2(exitRegion.getWidth(), exitRegion.getHeight()));
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