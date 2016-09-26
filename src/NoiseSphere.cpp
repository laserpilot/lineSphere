//
//  NoiseSphere.cpp
//  masterViz
//
//  Created by Blair Neal on 9/12/16.
//
//

#include "NoiseSphere.h"

NoiseSphere::NoiseSphere(){
    
}

NoiseSphere::~NoiseSphere(){
    
}

void NoiseSphere::setup(){
    
    numSpheres = 20;
    

    
    SphereParams.setName("Sphere Params");
    SphereParams.add(turbulence.set("Turbulence", 0, 0,1));
    SphereParams.add(shapeWarp.set("Shape Warp", 0, 0,7));
    SphereParams.add(lineCount.set("Line Count", 40, 1,70));
    SphereParams.add(nestCount.set("Nest Count", 2, 1,20));
    SphereParams.add(startRadius.set("Start Radius", 300, 1,1000));
    
    for (int i=0; i<numSpheres; i++){
        SingleSphere temp;
        temp.setup(i, ofRandom(50,300), 30+(i%5)*20);
        sph.push_back(temp);
    }
}

void NoiseSphere::update(){
    
    for(int i=0; i<sph.size(); i++){
        if(i<lineCount){
            sph[i].update();
            sph[i].setTurbulence(turbulence+disruptor*1);
            sph[i].setShapeWarp(shapeWarp+disruptor*5);
            sph[i].setRadius(startRadius-(i%nestCount)*startRadius/nestCount);
        }
        //sph[i].setRadius((i*0.5)*30*sin(ofGetElapsedTimef()));
        //sph[i].setRadius(30*sin(ofGetElapsedTimef()));

    }

}

void NoiseSphere::draw(){
    for(int i=0; i<sph.size(); i++){
        if(i<lineCount){
            sph[i].draw();
        }
    }
}

ofParameterGroup NoiseSphere::getParameters(){
    return SphereParams;
}