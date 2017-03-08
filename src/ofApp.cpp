#include "ofApp.h"

#include "TileMatrix.h"
#include "SpriteRenderer.h"
#include "TileType.h"

ofApp::ofApp()
	:
	m_levelAspect(1)
{
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
	ofSetFrameRate(60.0f);

	ofLogVerbose("ofApp") << "Starting application";

	screenResolution.x = ofGetWidth();
	screenResolution.y = ofGetHeight();

	levelResolution.y = screenResolution.y;
	levelResolution.x = levelResolution.y * m_levelAspect;
	glm::vec2 normResolution = levelResolution / levelResolution.y;

	levelRender.allocate(levelResolution.x, levelResolution.y, GL_RGBA);

	renderer = make_unique<SpriteRenderer>(&textures, levelResolution);


	// Level Visuals
	Level::LevelVisuals visuals;
	visuals.levelRegion = ofRectangle(0, 0, normResolution.x, normResolution.y);
	visuals.tileMatrixRegion = ofRectangle(0, 0, 1, 0.5);
	visuals.paddleSize = glm::vec2(0.1, 0.01);
	visuals.ballSize = glm::vec2(0.01, 0.01);
	visuals.tileMap[TileType::BASIC] = { TextureId::BASIC_0 };
	visuals.tileMap[TileType::STRONG] = { TextureId::STRONG_0, TextureId::STRONG_1 };

	// Level descriptor and parameters
	levelDescriptor.load("level0.png");
	Level::LevelParams params;
	params.tiles = make_shared<TileMatrix>(levelDescriptor);
	params.time = 120; // in secs
	params.paddlePosition = glm::vec2(0.5, 0.9);
	params.paddleSpeed = 4.0f;
	params.paddleFrictionCoeff = 40.0f;

	std::vector<Level::LevelParams> paramsVec;
	paramsVec.push_back(params);

	std::function<void()> onGameEnd = std::bind(&ofApp::onGameEnd, this);
	levels = make_unique<LevelManager>(paramsVec, visuals, onGameEnd);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto key : keyboard.getKeys())
	{
		if (key.second)
		{
			levels->input(key.first);
		}
	}

	double deltaTime = MIN (ofGetLastFrameTime(), 1.0 / ofGetFrameRate());
	levels->update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0);
	levels->draw(renderer.get());
}

void ofApp::onGameEnd()
{
	// credits or close.. or go back to menu
	ofExit();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
