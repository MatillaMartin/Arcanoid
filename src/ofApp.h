#pragma once

#include "ofMain.h"

#include "LevelManager.h"

class ofApp : public ofBaseApp{

	public:
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
		ofImage levelDescriptor;
		ofImage basicTile;
		ofImage strongTile_0;
		ofImage strongTile_1;
		ofImage paddle;
		ofImage ball;

		std::unique_ptr<LevelManager> levels;
};
