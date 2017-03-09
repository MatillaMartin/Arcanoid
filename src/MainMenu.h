#pragma once

#include "ofxEntityX.h"
#include "EventHandler.h"
#include "Screen.h"
#include "ofRectangle.h"
#include "MenuEvents.h"

class MainMenu : public ofxEntityX, public Screen, public Receiver<MainMenu>
{
public:
	struct Params
	{
		// in seconds
		double selectDelay;
	};
	struct Visuals
	{
		// layouts
		ofRectangle menuRegion;
		ofRectangle playRegion;
		ofRectangle creditsRegion;
		ofRectangle exitRegion;

		// map defining menu items
		std::map<MenuItem, std::pair<TextureId, TextureId>> menuItemMap;
	};

	struct Callbacks
	{
		std::function<void()> onPlay;
		std::function<void()> onCredits;
		std::function<void()> onExit;
	};

	MainMenu(const Params & params, const Visuals & visuals, const Callbacks & callbacks);
	void update(double delta) override;
	void draw(Renderer * renderer) override;
	void input(char input) override;

	void receive(const UseEvent & e);
	void receive(const SelectEvent & e);

private:
	void setupEntityX();
	void setupMenu();

	void onSelectVisualBehaviour(Entity selected);

	Visuals m_visuals;
	Callbacks m_callbacks;
	Params m_params;
};