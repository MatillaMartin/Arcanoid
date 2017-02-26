#include "ofApp.h"

#include "TileMatrix.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60.0f);

	levelDescriptor.load("level0.png");
	basicTile.load("basicTile.png");
	strongTile_0.load("strongTile_0.png");
	strongTile_1.load("strongTile_1.png");

	Level::LevelParams params;
	params.tiles = make_shared<TileMatrix>(levelDescriptor);
	params.time = 120; // in secs

	Level::LevelVisuals visuals;
	visuals.tileTextures[TileVisualComponent::TileVisual::BASIC] = basicTile.getTexture();
	visuals.tileTextures[TileVisualComponent::TileVisual::STRONG_0] = strongTile_0.getTexture();
	visuals.tileTextures[TileVisualComponent::TileVisual::STRONG_1] = strongTile_1.getTexture();
	visuals.tileMatrixRegion = ofRectangle(0, 0, 1000, 1000);

	level = make_unique<Level>(params, visuals);
}

//--------------------------------------------------------------
void ofApp::update(){
	double deltaTime = MIN (ofGetLastFrameTime(), 1.0 / ofGetFrameRate());
	level->update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw(){
	level->draw();
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
