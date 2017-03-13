#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofDisableArbTex();

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.width = 1024 / 4.0f;
	settings.height = 768 / 4.0f;

	ofCreateWindow(settings);

	ofRunApp(new ofApp());

}
