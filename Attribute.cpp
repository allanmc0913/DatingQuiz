/**
 * Attribute.cpp
 *
 * Allan Chen, Lisa Shrosbree
 * allanmc, shroslis
 *
 * EECS 183: Project 5
 *
 * All the relevant function/constructor implementations associated with
 * class Attribute
 */

#include "Attribute.h"

//default constructor initializing private data members index and points to 0
Attribute::Attribute() {
    
    index = 0;
    points = 0;
    
}

/*non-default constructor that initializes index and points to parameters after
 checking validity using putDataWithinRange function*/
Attribute::Attribute(int inIndex, int inPoints) {
    
    index = putDataWithinRange(inIndex);
    points = inPoints;
    
}

//member function returning index
int Attribute::getIndex() const {
    
    return index;
    
}

//returns points
int Attribute::getPoints() const {
    
    return points;
    
}

/*sets index to parameter value after checking validity using putDataWithinRange
 function*/
void Attribute::setIndex(int inIndex) {
    
    index = putDataWithinRange(inIndex);

}

//sets points to the corresponding parameter.
void Attribute::setPoints(int inPoints) {
    
    points = inPoints;
    
}

/*puts value within range from 0 to MAX_NUM_ATTRIBUTES. If it is already 
 in range,return value. If not, return 0 or MAX_NUM_ATTRIBUTES - 1,
whichever value is closest to*/
int Attribute::putDataWithinRange(int value) {
    
    if (value >= 0 && value < MAX_NUM_ATTRIBUTES) {
        
        return value;
        
    }
    
    else if (value < 0) {
        
        int minVal = 0;
        return minVal;
        
    }
    
    else if (value >= MAX_NUM_ATTRIBUTES) {
     
        return MAX_NUM_ATTRIBUTES - 1;
        
    }
    
    return 0;
    
}

/*reads in from istream into temp variables. If valid, set index and points to 
 their respective temp variables*/
void Attribute::read(istream& ins) {
    
    int tempIndex = 0;
    int tempPoints = 0;
    
    ins >> tempIndex >> tempPoints;
    
    
    if (tempIndex >= 0 && tempIndex <= MAX_NUM_ATTRIBUTES) {
        
        index = tempIndex;
        points = tempPoints;
        
    }
}

//outputs index and points from ostream
void Attribute::write(ostream& outs) const {
    
    outs << index;
    outs << points;
    
}

istream& operator>> (istream& ins, Attribute& attribute) {
    
    attribute.read(ins);
    return ins;
    
}

ostream& operator<< (ostream& outs, const Attribute& attribute) {
    
    attribute.write(outs);
    return outs;
    
}
