#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	
	float radius = 325;
	int deg_span = 15;
	for (int deg = 0; deg < 360; deg += deg_span) {

		float noise_x = radius * cos((deg + deg_span / 2) * DEG_TO_RAD);
		float noise_y = radius * sin((deg + deg_span / 2) * DEG_TO_RAD);
		float noise_value = ofNoise(noise_x * 0.003, noise_y * 0.003, ofGetFrameNum() * 0.005);
		ofSetColor(39, 39, 239, noise_value * 255);

		ofBeginShape();
		for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg++) {

			float x = radius * cos(tmp_deg * DEG_TO_RAD);
			float y = radius * sin(tmp_deg * DEG_TO_RAD);
			ofVertex(x, y);
		}
		ofVertex(0, 0);
		ofEndShape(true);
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}