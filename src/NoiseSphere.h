//
//  NoiseSphere.hpp
//  masterViz
//
//  Created by Blair Neal on 9/12/16.
//
//


#include "SingleSphere.h"

class NoiseSphere{
    
public:
    NoiseSphere();
    ~NoiseSphere();
    
    void setup();
    void update();
    void draw();
    ofParameterGroup getParameters();
    
    
    void setStartRadius(float _radius){
        startRadius = _radius;
    }
    
    void setNestCount(int _count){
        nestCount = _count;
    }
    
    void setLineCount(int _count){
        lineCount = _count;
    }
    
    void setTurbulence(float _turb){
        turbulence=_turb;
    }
    
    void setShapeWarp(float _warp){
        shapeWarp = _warp;
    }
    
    void setDisruptor(float _disruptor){
        disruptor = _disruptor;
    }
    
private:
    string name;
    
    vector<SingleSphere> sph;
    int numLines;
    ofParameterGroup SphereParams;
    ofParameter <float> turbulence;
    ofParameter <float> shapeWarp;
    ofParameter <int> lineCount;
    ofParameter <int> nestCount;
    ofParameter <int> startRadius;
    
    float disruptor;

    
};