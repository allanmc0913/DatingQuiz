/**
 * Question.cpp
 *
 * Allan Chen, Lisa Shrosbree
 * allanmc, shroslis
 *
 * EECS 183: Project 5
 *
 * All the relevant function/constructor implementations associated with
 * class Question
 */

#include "Question.h"

//default constructor that initializes private data members to empty/blank
Question::Question() {
    
    numAnswers = 0;
    questionPrompt = "";
    
    //answers is an array so for loop used to initialize each element to default
    for (int i = 0; i < MAX_NUMBER_OF_ANSWERS; i++) {
        
        Answer tempAnswer;
        answers[i] = tempAnswer;
        
    }
}

//member function that returns numAnswers
int Question::getNumAnswers() const {
    
    return numAnswers;
    
}

//returns questionPrompt
string Question::getQuestionPrompt() const {
    
    return questionPrompt;
    
}

/*returns answer at index after checking validity. If invalid, return
 default answer*/
Answer Question::getAnswer(int index) const {
    
    if (index >= 0 && index < MAX_NUM_ATTRIBUTES) {
        
        return answers[index];
        
    }
    
    else {
        
        //call default constructor
        Question();
        return answers[index];
        
    }
}

//sets value of questionPrompt to parameter
void Question::setQuestionPrompt(string inQuestionPrompt) {
    
    questionPrompt = inQuestionPrompt;
    
}

/*adds answer into the answers array if numAnswers < MAX_NUMBER_OF_ANSWERS.
 also increments numAnswers*/
void Question::addAnswer(const Answer &inAnswer) {
    
    if (numAnswers < MAX_NUMBER_OF_ANSWERS) {
        
        answers[numAnswers] = inAnswer;
        numAnswers++;
        
    }
}

//return attribute associated with the chosen answer after checking validity
Attribute Question::submitAnswer(int chosenAnswer) const {
    
    //create new variable of class attribute to be returned
    Attribute attributeFinal;
    
    //validity check for chosenAnswer
    if (chosenAnswer >= 1) {
        
        //using getAttribute function, store attribute into variable
        attributeFinal = answers[chosenAnswer - 1].getAttribute();
        
    }
    
    //return variable with stored attribute
    return attributeFinal;
    
}

/*puts value within range minValue <= value <= maxValue.  If in range, return
value.  If not in range, return minValue or maxValue, whichever is closest*/
int Question::putDataWithinRange(int value, int minValue, int maxValue) const {
    
    if (value >= minValue && value <= maxValue) {
        
        return value;
        
    }
    
    else if (value < minValue) {
    
        return minValue;
        
    }
    
    else if (value > maxValue) {
    
        return maxValue;
        
    }
    
    return 0;
    
}

//sets value of numAnswers after checking validity
void Question::setNumAnswers(int inNumAnswers) {
    
    if (inNumAnswers <= MAX_NUMBER_OF_ANSWERS) {
        
        numAnswers = inNumAnswers;
        
    }
}

/*initialize private data members from input stream following format listed in
 RME*/
void Question::read(istream& ins) {
    
    /*from istream, take in # of answers and store it in numAnswers. take in
     questionPrompt and store it in string questionPrompt using getline*/
    ins >> numAnswers;
    getline(ins, questionPrompt);
    
    //for loop to initialize each answer to each element in the answers array
    for (int i = 0; i < numAnswers; i++) {
        
        ins >> answers[i];
        
    }
}

//print question prompt and numbered answers to ostream
void Question::write(ostream& outs) const {
    
    outs << questionPrompt << endl;
    
    //for loop to print out each answer in answers array
    for (int i = 0; i < numAnswers; i++) {
        
        outs << i + 1 << ") " << answers[i].getText() << endl;
        
    }
}

istream& operator>> (istream& ins, Question& question) {
    question.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, const Question& question) {
    question.write(outs);
    return outs;
}

