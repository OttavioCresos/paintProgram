#include "ofApp.h"
/// COMMENT GUIDE:
/// Describe what function does
/// parameter NAME - what the parameter(s) should be
/// returns (describe what the function returns if it returns something)

//--------------------------------------------------------------
void ofApp::setup(){
	//fBackground(255); cooment out before implementing Fbo canvas
	canvasFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 2); //4th parameter is MSAA -> anti-aliasing (check Fbo doc for inf on anti-aliasing)
	//this clears the FBO at the start
	canvasFbo.begin();//every time we draw, we do it in between these 2 funcs
	ofClear(ofColor(250, 250, 250, 255));
	canvasFbo.end();
	//initialising my variables:
	mouseIsPressed = false;
	//other variables:
	distance = 0;
	previousMouseX = 0;
	previousMouseY = 0;
	//brushes on/off variables
	S_on = false;
	E_on = false;
	A_on = false;
	R_on = false;
	D_on = false;

}

//--------------------------------------------------------------
void ofApp::update(){

	if (mouseIsPressed) {
		canvasFbo.begin();
		// call your simple brush function here see step 2
		if (S_on) {
			simpleBrush(mouseX, mouseY);
		}
		else if (E_on) {
			eraserBrush(mouseX, mouseY);
		}
		else if (A_on) {
			anotherBrush(mouseX, mouseY);
		}
		else if (R_on) {
			ribbonBrush(mouseX, mouseY, distance);
		}
		else if (D_on) {
			dynamicBrush(mouseX, mouseY, distance);
		}
		canvasFbo.end();
	}
	//simpleBrush(mouseX, mouseY);
	//anotherBrush(mouseX, mouseY);
	//ribbonBrush(mouseX, mouseY);
	//dynamicBrush(mouseX, mouseY, distance);

	//LAB checking distance
	distance = ofDist(previousMouseX, previousMouseY, mouseX, mouseY);// CHECK IN OF DOCS ofDist
	//LAB storing our mouse value x & y in the previous mouse pos variables
	//update values
	previousMouseX = mouseX;
	previousMouseY = mouseY;

}

//--------------------------------------------------------------
void ofApp::draw(){

	canvasFbo.draw(0, 0);

}

	//**MY BRUSHES FUNCTIONS**//

	/// Draws an ellipse at x & y coordinates
	/// parameter x - the x coordinate of the mouse position
	/// parameter y - the y coordinate of the mouse position
	void ofApp::simpleBrush(float x, float y) {
		ofSetColor(50);
		ofDrawEllipse(x, y, 25, 25);
}

	//the eraser functioj draws a rectangle that acts as an eraser
	/// parameter x - the x coordinate of the mouse position
	/// parameter y - the y coordinate of the mouse position
	void ofApp::eraserBrush(float x, float y) {
		ofSetColor(250);
		ofSetRectMode(OF_RECTMODE_CENTER); //set rectangle mode to the center
		ofDrawRectangle(x, y, 50, 50);
	}

	void ofApp::anotherBrush(float x, float y) {
		ofSetColor(0, 0, ofRandom(255), ofRandom(255));
		ofDrawCircle(x + ofRandom(-35, 35), y + ofRandom(-35, 35), ofRandom(1, 5));
		ofSetColor(ofRandom(255), 0, 0, ofRandom(100, 255));
		ofDrawCircle(x + ofRandom(-35, 35), y + ofRandom(-35, 35), ofRandom(3, 10));
	}

	void ofApp::dynamicBrush(float x, float y, float speed) {
		ofSetColor(255, 215, 0, 200);

		//LAB ASSIGNMENT STEP
		//use speed parameter 
		float size = ofClamp(speed, 1, 50);//don't understand this passage, check Clamp function
		ofDrawCircle(x - 5, y - 5, size);
		ofDrawCircle(x + 5, y + 5, size);
	}

	void ofApp::ribbonBrush(float x, float y, float speed) {
		//we are going to use transformations
		ofPushMatrix();

		ofTranslate(x, y);

		//add rotation:
		ofRotateDeg(ofGetFrameNum() % 360);// I don't really get how modulo works.check it out

		
		ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(255));
		float size = ofClamp(speed, 1, 50);
		ofSetLineWidth(speed);
		ofDrawLine(-50, 0, 50, 0);

		ofPopMatrix();
	}

	//**END OF MY BRUSHES FUNCTIONS**//

void ofApp::keyPressed(int key) {
	if (key == 's') {
		S_on = true;
		E_on = false;
		A_on = false;
		R_on = false;
		D_on = false;
	}
	if (key == 'e') {
		S_on = false;
		E_on = true;
		A_on = false;
		R_on = false;
		D_on = false;
	}
	if (key == 'a') {
		S_on = false;
		E_on = false;
		A_on = true;
		R_on = false;
		D_on = false;
	}
	if (key == 'r') {
		S_on = false;
		E_on = false;
		A_on = false;
		R_on = true;
		D_on = false;
	}
	if (key == 'd') {
		S_on = false;
		E_on = false;
		A_on = false;
		R_on = false;
		D_on = true;
	}
}

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

	mouseIsPressed = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	mouseIsPressed = false;
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
