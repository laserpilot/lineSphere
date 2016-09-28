//
//  SingleSphere.cpp
//  masterViz
//
//  Created by Blair Neal on 9/12/16.
//
//

#include "SingleSphere.h"

void SingleSphere::setup(int _idIndex, int _maxNumPts, float _radius){
    pts.clear();
    uniqueValue = ofRandom(0,1);
    radius = _radius;
    indexId = _idIndex;
    noiseCursor = 0;
    maxNumPts = _maxNumPts;
    lineWidth = ofRandom(1,1);
    turbulence = 0;
    shapeWarp =0;
}

void SingleSphere::update(){
    
    noiseCursor +=0.004;
    noiseCursor = ofWrap(noiseCursor,0,50000);
    
    timePts.push_back(noiseCursor);
    if(timePts.size()>maxNumPts){
        timePts.erase(timePts.begin());
    }
    
    pts.clear();
    
    for(int i=0; i<timePts.size(); i++){
        float spherePct = 0.2+0.1*turbulence*ofSignedNoise(uniqueValue+50*timePts[i]);
        
        float ranPtU =ofMap(ofSignedNoise(0.5*timePts[i]+indexId*0.03+uniqueValue*timePts[i]),-spherePct,spherePct,0,2*PI);
        
        float ranPtV =ofMap(ofSignedNoise(0.5*timePts[i]+50+indexId*0.02+uniqueValue*timePts[i]),-spherePct,spherePct,0,PI);
        
        //ranPtU = ofClamp(ranPtU, 0,2*PI/2);
        
        
        
        ofVec3f temp;
        //Sphere Math
        
        float power = shapeWarp;
        
        float tempRadius = radius + shapeWarp *50*ofSignedNoise(i*0.03+noiseCursor);
        
        temp = ofVec3f(tempRadius*sin(ranPtV)*cos(ranPtU),
                       tempRadius*sin(ranPtV)*sin(ranPtU),
                       tempRadius*cos(ranPtV));
        
        pts.push_back(temp);

        if(pts.size()>maxNumPts){
            pts.erase(pts.begin());
        }
    }
    

    

}

void SingleSphere::draw(){

    ofPushMatrix();
    
    //ofRotateY(indexId*30);
    ofMesh lineMesh;
    lineMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    ofSetLineWidth(lineWidth);
    
    for(int j=0; j<pts.size(); j++){
        
        lineMesh.addVertex(pts[j]);
        
        if(indexId>0){
            lineMesh.addColor(ofColor(255,255,255,ofMap(j,0,pts.size(),0,255)));
        }else{
            lineMesh.addColor(ofColor(255,ofWrap(noiseCursor,0,255),255,ofMap(j,0,pts.size(),0,255)));
        }
        
    }
    
    lineMesh.draw();
    
    ofPopMatrix();
    
}

//vector<ofVec3f> SingleSphere::getPts{
//    return &pts;
//}