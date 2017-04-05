#pragma once

#include "ofMain.h"

#include "LevelManager.h"
#include "GameTextures.h"
#include "Keyboard.h"
#include "MainMenu.h"

class ofApp : public ofBaseApp{

	public:
		ofApp();
		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

private:
		void onPlay();
		void onCredits();
		void onExit();

		void onGameEnd();

		ofFbo levelRender;
		ofImage levelDescriptor;

		Keyboard keyboard;
		GameTextures textures;

		GameSounds sounds;
		SoundPlayer soundPlayer;

		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<LevelManager> levels;
		std::unique_ptr<MainMenu> menu;

		glm::vec2 screenResolution;
		glm::vec2 levelResolution;

		Screen * m_screen;
		float m_levelAspect;
};
