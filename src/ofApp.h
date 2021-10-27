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
		//my paint program functions:
		void simpleBrush(float x, float y);//S
		bool S_on;
		void eraserBrush(float x, float y);//E
		bool E_on;
		void anotherBrush(float x, float y);//A
		bool A_on;
		void ribbonBrush(float x, float y, float speed_2);//R
		bool R_on;
		void dynamicBrush(float x, float y, float speed);//D
		bool D_on;
		//my paint program variables:
		ofFbo canvasFbo;
		bool paintIsOn;

		bool eraserOn;
		bool mouseIsPressed;
		//create a couple of global variables to store that interaction state
		float distance;
		float previousMouseX;
		float previousMouseY;



		
};
