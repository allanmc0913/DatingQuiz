/**
 * Answer.cpp
 *
 * Allan Chen, Lisa Shrosbree
 * allanmc, shroslis
 *
 * EECS 183: Project 5
 *
 * All the relevant function/constructor implementations associated with
 * class Answer
 */

#include "Answer.h"

/*default constructor initializing private data members. Sets text to empty.
 attribute private data member was previously initialized in Attribute
 class*/
Answer::Answer() {
    
    text = "";
    
}

/*non-default constructor. getAttribute is a member function of class Answer,
 returning type Attribute*/
Attribute Answer::getAttribute() const {
    
    return attribute;
    
}

//returns text
string Answer::getText() const {
    
    return text;
    
}

//sets private data member attribute to parameter value inAttribute
void Answer::setAttribute(const Attribute &inAttribute) {
    
    attribute = inAttribute;
    
}

//sets private data member text to parameter value inText
void Answer::setText(string inText) {
    
    text = inText;
    
}

//reads in attribute and text from istream and initializes them
void Answer::read(istream& ins) {
    
    //create temp variables for attribute
    int indexIn;
    int pointsIn;
    
    //read in temp variables from istream
    ins >> indexIn;
    ins >> pointsIn;
    
    //calls Attribute class setters to initialize data
    attribute.setIndex(indexIn);
    attribute.setPoints(pointsIn);
    
    //use getline to read in the entire line into private data member text
    getline(ins, text);

}

//outputs text from ostream
void Answer::write(ostream& outs) const {
    
    outs << text;
    
}


istream& operator >> (istream& ins, Answer& answer) {
    
    answer.read(ins);
    return ins;
    
}

ostream& operator << (ostream& outs, const Answer& answer) {
    
    answer.write(outs);
    return outs;
    
}

