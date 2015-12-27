#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;
    settings.setGLVersion(4,1);
    settings.width = 1280;
    settings.height = 96;
    ofCreateWindow(settings);
	ofRunApp(new ofApp());
}
