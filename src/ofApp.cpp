#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sphere.setup();
    counter = 0;
    radiusOffset= 500;
    
    turbEnable = pulseEnable = warpEnable = true;
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
    
    if(warpEnable){
        sphere.setShapeWarp(3.5*ofSignedNoise(counter*0.02, counter*0.001));
    }else{
        sphere.setShapeWarp(0);
    }
    
    if(pulseEnable){
        sphere.setStartRadius(radiusOffset+(radiusOffset-100)*ofSignedNoise(counter*0.01, counter*0.004,200));
 
    }else{
        sphere.setStartRadius(radiusOffset);

    }
    
    if(turbEnable){
        sphere.setTurbulence(ofClamp(1*ofSignedNoise(counter*0.0001+400, counter*0.0004,600),0,1));

    }else{
        sphere.setTurbulence(0);
 
    }
    
    
    cam.begin();
    ofRotateZ(counter*7);
    ofRotateX(counter*10);
    sphere.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='1'){
        radiusOffset +=50;
    }
    
    if(key=='2'){
        radiusOffset -=50;
    }
    
    if(key=='3'){
        warpEnable = !warpEnable;
    }
    
    if(key=='4'){
        turbEnable = !turbEnable;
    }
    
    if(key=='5'){
        pulseEnable = !pulseEnable;
    }
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
