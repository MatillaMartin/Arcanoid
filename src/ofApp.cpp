#include "ofApp.h"

#include "TileMatrix.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex();
	ofLogToConsole();
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
	ofSetFrameRate(60.0f);

	ofLogVerbose("ofApp") << "Starting application";

	levelDescriptor.load("level0.png");
	basicTile.load("basicTile.png");
	strongTile_0.load("strongTile_0.png");
	strongTile_1.load("strongTile_1.png");
	paddle.load("paddle.png");
	ball.load("ball.png");

	Level::LevelParams params;
	params.tiles = make_shared<TileMatrix>(levelDescriptor);
	params.time = 120; // in secs
	params.paddlePosition = glm::vec2(0.5, 0.9);

	Level::LevelVisuals visuals;
	visuals.tileTextures[TileTexture::BASIC] = basicTile.getTexture();
	visuals.tileTextures[TileTexture::STRONG_0] = strongTile_0.getTexture();
	visuals.tileTextures[TileTexture::STRONG_1] = strongTile_1.getTexture();
	visuals.tileMatrixRegion = ofRectangle(0, 0, 1100, 500);
	visuals.paddleTexture = paddle.getTexture();
	visuals.ballTexture = ball.getTexture();
	visuals.ballRadius = (ball.getWidth() / 2.0f) * 10.0f;
	visuals.paddleSize = glm::vec2(paddle.getWidth() * 10, paddle.getHeight() * 10);
	visuals.levelRegion = ofRectangle(0, 0, 1100, 768);

	std::vector<Level::LevelParams> paramsVec;
	paramsVec.push_back(params);

	std::function<void()> onGameEnd = std::bind(&ofApp::onGameEnd, this);

	levels = make_unique<LevelManager>(paramsVec, visuals, onGameEnd)
}

//--------------------------------------------------------------
void ofApp::update(){
	double deltaTime = MIN (ofGetLastFrameTime(), 1.0 / ofGetFrameRate());
	levels->update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushStyle();
		ofNoFill();
		ofDrawRectangle(0, 0, 1100, 500);
	ofPopStyle();
	levels->draw();
}

void ofApp::onGameEnd()
{
	// credits or close..
	ofExit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
