#ifndef PERSONALITY_H
#define PERSONALITY_H

/**
 * Personality.h
 *
 * EECS 183: Project 5
 *
 * Header file for the Personality class.
 * Do NOT modify this file.
 */

#include<string>
#include "Attribute.h"

using std::string;
using std::istream;
using std::ifstream;
using std::fstream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

// a default Personality has this number of points for all attributes
const int DEFAULT_POINTS = 5;

const int MIN_POINTS = 0;
const int MAX_POINTS = 10;

const string ATTRIBUTE_NAMES[MAX_NUM_ATTRIBUTES] = {
    "Openness to Experience",
    "Conscientiousness",
    "Extraversion",
    "Agreeableness",
    "Neuroticism"
};


class Personality {

public:
    /**
     * Requires: Nothing.
     * Modifies: Private data.
     * Effects:  Default constructor.
     *           Initializes the points array to its default state.
     */
    Personality();
    
    /**
     * Requires: Nothing.
     * Modifies: Private data.
     * Effects:  Resets the points array to its default state.
     */
    void reset();
    
    /**
     * Requires: Nothing.
     * Modifies: points array.
     * Effects:  Adds the attribute of the answer into the Personality.
     *           The Attribute index corresponds to the index in the points
     *           array, while its point value determines the value that should
     *           be added to that element in the array. If subtraction of
     *           points yields a value that is below MIN_POINTS, the value 
     *           stored in the points array will be MIN_POINTS. 
     *           If an addition surpasses MAX_POINTS, then the value stored
     *           into the points array will be MAX_POINTS.
     */
    void adjustPersonality(const Attribute& inAttribute);
    
    
    /**
     * Requires: outs is in a good state.
     * Modifies: outs.
     * Effects:  Prints out the personality profile.
     */
    friend ostream& operator<< (ostream& outs, const Personality& personality);
    
    
private:
    /**
     * Array of the personality points. For example, points[0] refers to
     * how many "Openness to Experience" points this Personality has.
     */
    int points[MAX_NUM_ATTRIBUTES];
    
    
    /**
     * Requires: outs is in a good state.
     * Modies:   outs.
     * Effects:  Prints out the personality profile (see example in the spec).
     */
    void write(ostream& outs) const;
    
};

#endif

