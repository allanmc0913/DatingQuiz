#ifndef QUESTION_H
#define QUESTION_H

/**
 * Question.h
 *
 * EECS 183: Project 5
 *
 * Header file for the Question class.
 * Do NOT modify this file.
 */

#include <iostream>
#include <string>

#include "Answer.h"
#include "Attribute.h"
#include "Personality.h"

using std::string;
using std::istream;
using std::ostream;

// total possible number of choosable answers a Question can have
const int MAX_NUMBER_OF_ANSWERS = 10;


class Question {
    
public:
    /**
     * Requires: Nothing.
     * Modifies: numAnswers, questionPrompt, answers.
     * Effects:  Initializes the object to a completely empty/blank Question.
     */
    Question();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns numAnswer.
     */
    int getNumAnswers() const;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns questionPrompt.
     */
    string getQuestionPrompt() const;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the answer at index after checking its validity.
     *           If index is invalid, returns a default Answer.
     */
    Answer getAnswer(int index) const;

    /**
     * Requires: Nothing.
     * Modifies: questionPrompt.
     * Effects:  Sets the value of questionPrompt.
     */
    void setQuestionPrompt(string inQuestionPrompt);
    
    /**
     * Requires: Nothing.
     * Modifies: answers.
     * Effects:  Adds answer into the answers array at the end if
     *           numAnswers < MAX_NUMBER_OF_ANSWERS and increments numAnswers.
     */
    void addAnswer(const Answer& inAnswer);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Submit the answer to this question (supplied by the user).
     *           All this does is return the attribute associated with the
     *           chosen answer (after checking its validity) so that it can be
     *           accumulated into the Personality. Remember 'answers' is
     *           an array and 'chosenAnswer' is NOT zero-based.
     */
    Attribute submitAnswer(int chosenAnswer) const;
    
    /**
     * Requires: ins is in a good state.
     * Modifies: ins, question.
     * Effects:  Initializes private members from the given input stream.
     * Note:     A great way to input a Question.
     */
    friend istream& operator>> (istream& ins, Question& question);
    
    /**
     * Requires: outs is in a good state.
     * Modifies: outs.
     * Effects:  Prints the question and numbered answers to the output stream.
     * Note:     A great way to print out a Question.
     */
    friend ostream& operator<< (ostream& outs, const Question& question);
    
    
private:
    /**
     * The number of chooseable answers for this question.
     * It must be less than or equal to MAX_NUMBER_OF_ANSWERS.
     */
    int numAnswers;
    
    /**
     * The prompt, i.e. "What's your favorite color?"
     * Note: as a general rule, you're not supposed to put
     * "using namespace std;" into header files,
     * so we added "using std::string" at the top of this file.
     */
    string questionPrompt;
    
    /**
     * The array of chooseable Answers to the question.
     */
    Answer answers[MAX_NUMBER_OF_ANSWERS];
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Puts value within range of minValue <= value <= maxValue.
     *           If within range, returns value. If not, returns either
     *           minValue or maxValue, whichever is closest.
     */
    int putDataWithinRange(int value, int minValue, int maxValue) const;
    
    
    /**
     * Requires: Nothing.
     * Modifies: numAnswers.
     * Effects:  Sets the value of numAnswers after checking its validity.
     */
    void setNumAnswers(int inNumAnswers);
    
    
    /**
     * Requires: ins is in a good state.
     * Modifies: ins and private data.
     * Effects:  Initialize private members from the given input stream.
     *           The stream will most likely be a file, but could be keyboard.
     *           That will be determined in the calling program.
     * Format:   #of answers followed by the question prompt
     *           the next lines are the answers
     *           (remember these are in the format of an Answer)
     * Note:     You will need to assume that the number of answers and
     *           the number of actual answers match.
     */
    void read(istream& ins);
    
    
    /**
     * Requires: outs is in a good state.
     * Modifies: outs.
     * Effects:  Prints the question and numbered answers to the output stream.
     * Format:   Do you enjoy EECS183?    <--this is the question
     *           1) Yes                   <--these are the numbered answers
     *           2) No
     */
    void write(ostream& outs) const;
    
};

#endif

