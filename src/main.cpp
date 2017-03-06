#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofDisableArbTex();

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.width = 1024;
	settings.height = 768;

	ofCreateWindow(settings);

	ofRunApp(new ofApp());

}
