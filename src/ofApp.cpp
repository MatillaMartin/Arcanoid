#include "ofApp.h"

#include "TileMatrix.h"
#include "SpriteRenderer.h"
#include "TileType.h"

ofApp::ofApp()
	:
	m_levelAspect(1),
	m_screen(nullptr),
	keyboard({ 'w', 'a', 's', 'd', ' ' })
{
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
	ofSetFrameRate(60.0f);
	ofSetBackgroundAuto(true);

	ofLogVerbose("ofApp") << "Starting application";

	screenResolution.x = ofGetWidth();
	screenResolution.y = ofGetHeight();

	levelResolution.y = screenResolution.y;
	levelResolution.x = levelResolution.y * m_levelAspect;
	glm::vec2 normResolution = levelResolution / levelResolution.y;

	levelRender.allocate(levelResolution.x, levelResolution.y, GL_RGBA);

	renderer = make_unique<SpriteRenderer>(&textures, levelResolution);


	// Main Menu
	MainMenu::Params mainMenuParams;
	mainMenuParams.selectDelay = 0.2;

	MainMenu::Visuals mainMenuVisuals;
	mainMenuVisuals.menuRegion = ofRectangle(0, 0, normResolution.x, normResolution.y);
	mainMenuVisuals.playRegion = ofRectangle(0.2, 0.1, 0.6, 0.2);
	mainMenuVisuals.creditsRegion = ofRectangle(0.2, 0.4, 0.6, 0.2);
	mainMenuVisuals.exitRegion = ofRectangle(0.2, 0.7, 0.6, 0.2);
	mainMenuVisuals.menuItemMap[MenuItem::MENU_PLAY] = { TextureId::PLAY, TextureId::PLAY_SEL };
	mainMenuVisuals.menuItemMap[MenuItem::MENU_CREDITS] = { TextureId::CREDITS, TextureId::CREDITS_SEL };
	mainMenuVisuals.menuItemMap[MenuItem::MENU_EXIT] = { TextureId::EXIT, TextureId::EXIT_SEL };
	mainMenuVisuals.menuItemMap[MenuItem::MENU_NONE] = { TextureId::NONE, TextureId::NONE };

	MainMenu::Callbacks mainMenuCallbacks;
	mainMenuCallbacks.onPlay = std::bind(&ofApp::onPlay, this);
	mainMenuCallbacks.onCredits = std::bind(&ofApp::onCredits, this);
	mainMenuCallbacks.onExit = std::bind(&ofApp::onExit, this);
	menu = make_unique<MainMenu>(mainMenuParams, mainMenuVisuals, mainMenuCallbacks);

	// Level Visuals
	Level::Visuals visuals;
	visuals.levelRegion = ofRectangle(0, 0, normResolution.x, normResolution.y);
	visuals.tileMatrixRegion = ofRectangle(0, 0, 1, 0.5);
	visuals.paddleSize = glm::vec2(0.1, 0.01);
	visuals.ballSize = glm::vec2(0.01, 0.01);
	visuals.tileMap[TileType::BASIC] = { TextureId::BASIC_0 };
	visuals.tileMap[TileType::STRONG] = { TextureId::STRONG_0, TextureId::STRONG_1 };

	// Level descriptor and parameters
	levelDescriptor.load("level0.png");
	//levelDescriptor.load("level1.png");
	Level::Params params;
	params.tiles = make_shared<TileMatrix>(levelDescriptor);
	params.time = 120; // in secs
	params.paddlePosition = glm::vec2(0.5, 0.9);
	params.paddleSpeed = 0.04f;
	params.paddleFrictionCoeff = 40.0f;
	params.paddleStickTime = 3.0f;
	params.ballSpeed = 0.02f; // screen fractions per second

	std::vector<Level::Params> paramsVec;
	paramsVec.push_back(params);

	std::function<void()> onGameEnd = std::bind(&ofApp::onGameEnd, this);
	levels = make_unique<LevelManager>(paramsVec, visuals, onGameEnd);

	// first screen is the main menu
	m_screen = menu.get();
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto key : keyboard.getKeys())
	{
		if (key.second)
		{
			m_screen->input(key.first);
		}
	}

	double deltaTime = MIN (ofGetLastFrameTime(), 1.0 / ofGetFrameRate());
	m_screen->update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(255);
	m_screen->draw(renderer.get());
}

void ofApp::onGameEnd()
{
	// credits or close.. or go back to menu
	ofExit();
}

void ofApp::onPlay()
{
	keyboard.clear();
	// load first level
	levels->load(0);
	// change the current screen to the level manager
	m_screen = levels.get();
}

void ofApp::onCredits()
{
	// credits
	//m_screen = credits.get();
}

void ofApp::onExit()
{
	// call OF exit
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
