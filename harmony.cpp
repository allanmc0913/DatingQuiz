/**
 * harmony.cpp
 *
 * Allan Chen, Lisa Shrosbree
 * allanmc, shroslis
 *
 * EECS 183: Project 5
 *
 * Main driver program that assembles all four classes/functions
 * together to create the final harmony program.
 */

#include <iostream>
#include <fstream>
#include <string>

//used only for saveProfile()
#include <sstream>

#include "Personality.h"
#include "Question.h"
#include "Attribute.h"

using namespace std;

//number of options on the menu
const int NUM_MENU_OPTIONS = 5;

//maximum number of quizzes you can take
const int MAX_QUIZZES = 5;
const char * OUTPUT_FILE_NAME = "MyProfile.efc";


/**
 * The following functions are implemented for you.
 */

/**
 * Requires: inFile is in a good state.
 * Modifies: inFile.
 * Effects:  Prompts user for a file name and opens inFile, reprompting
 *           if there are errors. Returns the file name.
 */
string openFile(ifstream& inFile);


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints the welcome message.
 */
void printOpeningMessage();


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints the main menu and prompts for a command.
 */
void printMenu();


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints the closing message.
 */
void printClosingMessage();


/**
 * Requires: Nothing.
 * Modifies: personality.
 * Effects:  Writes the personality profile to an encoded file.
 * Note:     This function is intentionally obfusctated; you are not required
 *           to understand why or how it does what it does.
 */
void saveProfile(Personality& personality);


/**
 * You must implement the following functions.
 */

/**
 * Requires: min and max to be valid.
 * Modifies: cin.
 * Effects:  Reads and returns a number from cin. Continually repeats until
 *           the number is in rage [min, max] (see the spec for an example).
 */
int getNumberInRange(int min, int max);


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns true if and only if fileName is one of the strings in
 *           takenQuizFileNames; returns false otherwise.
 */
bool quizHasBeenTaken(string fileName, string takenQuizFileNames[MAX_QUIZZES],
                      int numberOfQuizzesTaken);


/**
 * Requires: quizFile is in a good state.
 * Modifies: personality.
 * Effects:  Reads a quiz from quizFile and presents questions one at a time
 *           to the user. Based on the user's response to each question,
 *           personality is modified.
 */
void takeQuiz(ifstream& quizFile, Personality& personality);


int main() {
    
    printOpeningMessage();
    
    //variable of class personality to be used throughout
    Personality personalityVariable;
    
    //variable to store the file name of quiz that has been taken
    string fileNameOfQuizTaken;
    
    //variable to store the number of quizzes taken
    int numberOfQuizzesTaken = 0;
    
    //array of taken file names that are of type string
    string takenQuizFileNames[MAX_QUIZZES];
    
    bool done = false;
    
    while(!done) {
        
        //calls function to print menu
        printMenu();
        
        //variable to take in the command the user enters
        int userInput;
        
        //calls getNumberInRange function
        userInput = getNumberInRange(1, NUM_MENU_OPTIONS);
        
        switch(userInput) {
                
            case 1:
                
                //if user has taken all the quizzes, output statement
                if (numberOfQuizzesTaken == MAX_QUIZZES) {
                    
                    cout <<
                    "You have already taken the maximum number of quizzes!"
                    << endl;
                    
                }
                
                else {
                    
                    //declare and open file stream for reading.
                    ifstream ifs;
                    fileNameOfQuizTaken = openFile(ifs);
                    
                    //check if quiz has been taken. If so output statement
                    if (quizHasBeenTaken(fileNameOfQuizTaken, takenQuizFileNames
                                         , numberOfQuizzesTaken)) {
                        
                        cout << "You've already taken that quiz!" << endl;
                        
                    }
                    
                    else {
                        
                        /*saves file name to array to keep track which quizzes
                         have been taken*/
                        takenQuizFileNames[numberOfQuizzesTaken] =
                        fileNameOfQuizTaken;
                        
                        //takes the quiz by calling function
                        takeQuiz(ifs, personalityVariable);
                        
                        //increments numberOfQuizzesTaken after taking quiz
                        numberOfQuizzesTaken += 1;
                        
                    }
                }
                
                break;
                
                
            case 2:
                
                //prints personality profile
                cout << personalityVariable << endl;
                
                break;
                
                
            case 3:
                
                //saves personality profile to file
                saveProfile(personalityVariable);
                
                break;
                
                
            case 4:
                
                //resets personality profile
                personalityVariable.reset();
                
                break;
                
                
            case 5:
                
                // time to end the loop!
                done = true;
                
                break;
                
        }
    }
    
    printClosingMessage();
    return 0;
    
}


/**
 * You must implement the following functions.
 */

/*Reads and returns number from cin. Has to be in range. If not, keep prompting
 user*/
int getNumberInRange(int min, int max) {
    
    int enteredValue;
    string junk;
    
    if (cin >> enteredValue) {
        
        if (enteredValue == 1 || enteredValue == 2 || enteredValue == 3
            || enteredValue == 4 || enteredValue == 5) {
            
            return enteredValue;
        }
        
        else {
            cout << "Invalid response! Please enter a number between " << min <<
            " and " << max << ": ";
        }
    }
    
    while (cin) {
    
        cout << "Invalid response! Please enter a number between " << min <<
        " and " << max << ": ";
    
            
    }
    return 0;
}

/*Returns true if and only if fileName is one of the strings in
 takenQuizFileNames; returns false otherwise*/
bool quizHasBeenTaken(string fileName, string takenQuizFileNames[MAX_QUIZZES],
                      int numberOfQuizzesTaken) {
    
    for (int i = 0; i < numberOfQuizzesTaken; i++) {
        
        if (fileName == takenQuizFileNames[i]) {
            
            return true;
            
        }
    }
    
    return false;
    
}

//function that takes the quiz from user inputted file
void takeQuiz(ifstream& quizFile, Personality& personality) {
    
    //variable to store quiz title
    string quizTitle;
    
    //variable to store number of questions
    int numQuestions;
    
    //take in entire title
    getline(quizFile, quizTitle);
    
    //take in number of questions
    quizFile >> numQuestions;
    
    //output title
    cout << endl << endl;
    cout << quizTitle << endl;
    
    //variable for the answer number the user enters
    int chosenAnswer;
    
    //loop through all the questions
    for (int i = 0; i < numQuestions; i++) {
        
        //object of class Question
        Question question;
        
        //take in all data associated with question
        quizFile >> question;
        
        //output statements
        cout << endl << "Question " << i + 1;
        cout << " out of ";
        cout << numQuestions << endl;
        
        //output all the variables associated with Question class
        cout << question << endl;
        
        //prompt user for input and take in their command
        cout << "Enter your answer: ";
        cin >> chosenAnswer;
        
        //new variable of class Attribute
        Attribute submittedAnswer;
        
        //call function to submit chosenAnswer
        submittedAnswer = question.submitAnswer(chosenAnswer);
        
        //uses submittedAnswer to modify personality using adjustPersonality
        personality.adjustPersonality(submittedAnswer);
        
    }
    
    //output final message
    cout << endl << "Congratulations, you've finished the quiz!" << endl
    << "Be sure to take a look at your updated"
    << " EECS Harmony Personality Profile!"
    << endl;
    
}

/**
 * Do NOT change implementations of the following functions.
 */

string openFile(ifstream& inFile) {
    
    // get file name from user
    cout << "Enter the quiz input file name: ";
    string quizFileName;
    cin >> quizFileName;
    
    // attempt to open file
    inFile.open(quizFileName.c_str());
    
    // keep asking until file is open
    while(!inFile) {
        inFile.clear();
        cout << "Couldn't open quiz input file!" << endl;
        cout << "Enter the quiz input file name: ";
        cin >> quizFileName;
        inFile.open(quizFileName.c_str());
    }
    
    return quizFileName;
}

void printOpeningMessage() {
    cout << "*************************************************" << endl
    << "*****             Welcome to the            *****" << endl
    << "*****    EECS Harmony Friendship Machine    *****" << endl
    << "*************************************************" << endl;
}

void printMenu() {
    cout << endl
    << "1) Take the Quiz" << endl
    << "2) Print Your Personality Profile" << endl
    << "3) Save Personality Profile to File" << endl
    << "4) Reset Personality Profile" << endl
    << "5) Quit" << endl << endl
    << "Enter command: ";
}

void printClosingMessage() {
    cout << "*************************************************" << endl
    << "*****        Thank you for using the        *****" << endl
    << "*****    EECS Harmony Friendship Machine    *****" << endl
    << "*************************************************" << endl << endl;
}

void saveProfile(Personality& p) {
   
     stringstream whatIsThis;whatIsThis<<p;int $;string soComplex;
     whatIsThis>>soComplex;int onbegrijpelijkharibo = 0;int $$$ = 2;int ___ =
     static_cast<int>(soComplex.length())+whatIsThis.good();
     ofstream xyz(OUTPUT_FILE_NAME);for(unsigned int x=xyz.good();x<___;x++)
     {whatIsThis>>soComplex;$$$ += 1;}for (unsigned int __=0;
     $$$*=8,$=71, __<___; onbegrijpelijkharibo+=1){for(;___>__;--___)
     {whatIsThis>>soComplex;onbegrijpelijkharibo = 10*isdigit(soComplex[
     soComplex.length() - 2*whatIsThis.good()]);onbegrijpelijkharibo +=
     soComplex[soComplex.length() - whatIsThis.good()] - $$$;
     xyz<<static_cast<char>(onbegrijpelijkharibo*___+$)<<'|';}}xyz.close();
     
}
