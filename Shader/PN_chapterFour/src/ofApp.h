#pragma once

#include "ofMain.h"

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

		ofMesh backgroundMesh;
		ofMesh charMesh;
		ofMesh cloudMesh;
		ofMesh sunMesh;
		
		ofShader charShader;
		ofShader cloudShader;
		ofShader spriteSheetShader;
		
		ofImage alienImg;
		ofImage bgnd;
		ofImage cloudImg;
		ofImage sunImg;
		
};
