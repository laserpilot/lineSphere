#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sphere.setup();
    counter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    sphere.update();
    counter+= 0.04;
    counter = ofWrap(counter,0,40000);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    
    sphere.setShapeWarp(3.5*ofSignedNoise(counter*0.02, counter*0.001));
    sphere.setStartRadius(800+700*ofSignedNoise(counter*0.01, counter*0.004,200));
        sphere.setTurbulence(1*ofSignedNoise(counter*0.001+400, counter*0.004,600));
    cam.begin();
    ofRotateZ(counter*7);
    ofRotateX(counter*10);
    sphere.draw();
    cam.end();
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
