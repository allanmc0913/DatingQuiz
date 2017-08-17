#ifndef ANSWER_H
#define ANSWER_H

/**
 * Answer.h
 *
 * EECS 183: Project 5
 *
 * Header file for the Answer class.
 * Do NOT modify this file.
 */

#include <iostream>
#include <string>

#include "Attribute.h"

using std::istream;
using std::ostream;
using std::string;


class Answer {
    
public:
    /**
     * Requires: Nothing.
     * Modifies: private data members.
     * Effects:  Default constructor.
     *           Initializes private members to default or empty values.
     */
    Answer();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns attribute.
     */
    Attribute getAttribute() const;
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns text.
     */
    string getText() const;
    
    
    /**
     * Requires: inAttribute is a valid Attribute.
     * Modifes:  attribute.
     * Effects:  Initializes private data attribute using the parameter.
     */
    void setAttribute(const Attribute& inAttribute);
    
    /**
     * Requires: Nothing.
     * Modifies: text.
     * Effects:  Initializes private data text using the parameter.
     */
    void setText(string inText);
    
    
    /**
     * Requires: ins is in a good state.
     * Modifies: ins, ans.
     * Effects:  Initializes private members from the given input stream.
     * Note:     A great way to input an Answer.
     */
    friend istream& operator>> (istream& ins, Answer& ans);
    
    
    /**
     * Requires: outs is in a good state.
     * Modifies: outs.
     * Effects:  Prints the question and numbered answers to the output stream.
     * Note:     A great way to print out an Answer.
     */
    friend ostream& operator<< (ostream& outs, const Answer& ans);
    
    
private:
    // The personality attribute associated with this answer.
    Attribute attribute;
    
    // The text for this Answer.
    string text;
    
    
    /**
     * Requires: ins to be in a good state.
     * Modifies: ins, attribute, text.
     * Effects:  Initializes private data members from the input stream.
     * Format:   attribute text
     * Example:  2 2calm
     */
    void read(istream& ins);
    
    
    /**
     * Requires: outs to be in a good state.
     * Modifies: outs.
     * Effects:  Prints answer text to the output stream.
     */
    void write(ostream& outs) const;
    
};

#endif

