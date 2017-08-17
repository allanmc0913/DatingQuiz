#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

/**
 * Attribute.h
 *
 * EECS 183: Project 5
 *
 * Header file for the Attribute class.
 * Do NOT modify this file.
 */

#include <iostream>

using std::istream;
using std::ostream;

// maximum number of Personality attributes
const int MAX_NUM_ATTRIBUTES = 5;

class Attribute {

public:
    
    // constructors
    
    /**
     * Requires: Nothing
     * Modifies: index, points
     * Effects: initializes private data to 0
     */
    Attribute();
    
    /**
     * Requires: nothing
     * Modifies: index, points
     * Effects:  sets index and points to the corresponding parameters
     * after checking for validity
     */
    Attribute(int inIndex, int inPoints);
    
    
    // accessors
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns index.
     */
    int getIndex() const;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns points.
     */
    int getPoints() const;
    
    /**
     * Requires: Nothing.
     * Modifies: index.
     * Effects:  Sets index to the corresponding parameter
     *           after checking for validity.
     */
    void setIndex(int inIndex);
    
    /**
     * Requires: Nothing.
     * Modifies: Points.
     * Effects:  Sets points to the corresponding parameter.
     */
    void setPoints(int inPoints);
    
    
    /**
     * Requires: ins is in a good state.
     * Modifies: ins, attribute.
     * Effects:  Reads in values from the input stream into attribute.
     * Note:     A great way to read in an Attribute.
     */
    friend istream& operator>> (istream& ins, Attribute& attribute);
    
    /**
     * Requires: outs is in a good state.
     * Modifies: outs.
     * Effects:  Writes attribute values to the output stream.
     * Note:     A great way to print out an Attribute.
     */
    friend ostream& operator<< (ostream& outs, const Attribute& attribute);

    
private:
    // every personality attribute has a unique index,
    // from 0 to MAX_NUM_ATTRIBUTES - 1
    int index;
    
    // points associated with this attribute
    int points;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Puts value within range of 0 <= value < MAX_NUM_ATTRIBUTES
     *           If within range, returns value; if not, returns either 0
     *           MAX_NUM_ATTRIBUTES - 1, whichever is closest.
     */
    int putDataWithinRange(int value);
    
    /**
     * Requires: ins is in a good state
     * Modifies: ins, attribute
     * Effects:  Reads in values from the input stream into index
     *           and points after checking their validity.
     * Format:   index points
     */
    void read(istream& ins);
    
    /**
     * Requires: outs is in a good state.
     * Modifies: outs.
     * Effects:  Prints index and points to the output stream.
     * Format:   index points
     */
    void write(ostream& outs) const;
    
};

#endif

