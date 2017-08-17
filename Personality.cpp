/**
 * Personality.cpp
 *
 * Allan Chen, Lisa Shrosbree
 * allanmc, shroslis
 *
 * EECS 183: Project 5
 *
 * All the relevant function/constructor implementations associated with
 * class Personality
 */

#include "Personality.h"

#include <iostream>
using std::endl;

//default constructor that sets every element in points array to default state
Personality::Personality() {
    
    for (int i = 0; i < MAX_NUM_ATTRIBUTES; i++) {
        
        points[i] = DEFAULT_POINTS;
        
    }
}

//member function that resets each element in points array to default state
void Personality::reset() {
    
    for (int i = 0; i < MAX_NUM_ATTRIBUTES; i++) {
        
        points[i] = DEFAULT_POINTS;
        
    }
}

/*Adds points from answer into existing values of points array. If total value
 is less than MIN_POINTS, value is defaulted to MIN_POINTS.  If
 total value is more than MAX_POINTS, value is defaulted to MAX_POINTS.*/
void Personality::adjustPersonality(const Attribute &inAttribute) {
    
    int tempPoints;
    tempPoints = points[inAttribute.getIndex()] + inAttribute.getPoints();
    
    if (tempPoints < MIN_POINTS) {
        
        tempPoints = MIN_POINTS;
        
    }
    
    if (tempPoints > MAX_POINTS) {
        
        tempPoints = MAX_POINTS;
        
    }
    
    points[inAttribute.getIndex()] = tempPoints;
        
}

/*outputs Personality Profile format listed in spec and the points value for
 each respective attribute*/
void Personality::write(ostream& outs) const {
    
    outs << "Your EECS Harmony Personality Profile" << endl;
    outs << "    Openness to Experience: " << points[0] << endl;
    outs << "    Conscientiousness: " << points[1] << endl;
    outs << "    Extraversion: " << points[2] << endl;
    outs << "    Agreeableness: " << points[3] << endl;
    outs << "    Neuroticism: " << points[4] << endl;
    
}

ostream& operator<< (ostream& outs, const Personality& personality) {
    personality.write(outs);
    return outs;
    
}

