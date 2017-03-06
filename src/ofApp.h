#pragma once

#include "ofMain.h"

#include "LevelManager.h"
#include "GameTextures.h"
#include "Keyboard.h"

class ofApp : public ofBaseApp{

	public:
		ofApp();
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
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
		void onGameEnd();

		GameTextures textures;
		Keyboard keyboard;

		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<LevelManager> levels;

		ofImage levelDescriptor;

		glm::vec2 screenResolution;
		glm::vec2 levelResolution;
		ofFbo levelRender;

		float m_levelAspect;
};
