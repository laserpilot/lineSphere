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
    
    
    void setDisruptor(float _disruptor){
        disruptor = _disruptor;
    }
    
private:
    string name;
    
    vector<SingleSphere> sph;
    int numSpheres;
    ofParameterGroup SphereParams;
    ofParameter <float> turbulence;
    ofParameter <float> shapeWarp;
    ofParameter <int> lineCount;
    ofParameter <int> nestCount;
    ofParameter <int> startRadius;
    
    float disruptor;
    
};