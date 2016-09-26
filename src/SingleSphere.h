//
//  SingleSphere.hpp
//  masterViz
//
//  Created by Blair Neal on 9/12/16.
//
//

#include "ofMain.h"

class SingleSphere{
    
public:
    SingleSphere() {};
    ~SingleSphere() {};
    
    void setup(int _idIndex, int _maxNumPts, float _radius);
    void update();
    void draw();
    
    //vector <ofVec3f> *getPts;
    
    void setTurbulence(float _turb){
        turbulence = _turb;
    }
    void setShapeWarp(float _shapeWarp){
        shapeWarp = _shapeWarp;
    }
    void setRadius (float _radius){
        radius = _radius;
    }
    
private:
    int indexId;
    vector <ofVec3f> pts;
    vector <float> timePts;
    float uniqueValue;
    int maxNumPts; //how long should the vec be
    float radius;
    float noiseCursor;
    float lineWidth;
    float shapeWarp;
    float turbulence;
};