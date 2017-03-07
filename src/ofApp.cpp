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

	levelRender.allocate(levelResolution.x, levelResolution.y, GL_RGBA);

	renderer = make_unique<SpriteRenderer>(&textures, levelResolution);

	levelDescriptor.load("level0.png");

	Level::LevelParams params;
	params.tiles = make_shared<TileMatrix>(levelDescriptor);
	params.time = 120; // in secs
	params.paddlePosition = glm::vec2(0.5, 0.9);
	params.paddleSpeed = 1.0f;
	params.paddleFrictionCoeff = 2.0f;

	std::vector<Level::LevelParams> paramsVec;
	paramsVec.push_back(params);

	glm::vec2 normResolution = levelResolution / levelResolution.y;

	Level::LevelVisuals visuals;
	visuals.levelRegion = ofRectangle(0, 0, normResolution.x, normResolution.y);
	visuals.tileMatrixRegion = ofRectangle(0, 0, 1, 0.5);

	// fixed size
	visuals.paddleSize = glm::vec2(0.1, 0.01);
	visuals.ballSize = glm::vec2(0.01, 0.01);

	visuals.tileMap[TileType::BASIC] = { TileTexture::BASIC_0 };
	visuals.tileMap[TileType::STRONG] = { TileTexture::STRONG_0, TileTexture::STRONG_1};

	std::function<void()> onGameEnd = std::bind(&ofApp::onGameEnd, this);
	levels = make_unique<LevelManager>(paramsVec, visuals, onGameEnd);
}

//--------------------------------------------------------------
void ofApp::update(){
	//for (auto key : keyboard.getKeys())
	//{
	//	if (key)
	//	{
	//		TODO

	//	}
	//}

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
	// credits or close..
	ofExit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	keyboard.onKeyPress(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	keyboard.onKeyRelease(key);
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
