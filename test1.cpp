//
//  test.cpp
//  Project 5
// Lisa Shrosbree, Allan Chen
// shroslis, allanmc
//
//  Created by Lisa Shrosbree on 3/17/15.
//  Copyright (c) 2015 Lisa Shrosbree. All rights reserved.
//

#include <stdio.h>
#include "Attribute.h"
#include "Personality.h"
#include "Question.h"
#include "Answer.h"
#include <iostream>


using namespace std;

int main(){
    
    //Attribute test cases
    
    
    Attribute object;
    //this is secretly a function call (the default constructor)
    //call get on a lot of variables and cout what you get
    cout << object.getIndex();
    
    
    //
    Attribute object2(-10,20);
    Attribute object3(-11, 9);
    Attribute object4(2, 23);
    
    cout << object.getIndex();
    cout << object.getPoints();
    cout << object2.getIndex();
    cout << object2.getPoints();
    cout << object3.getIndex();
    cout << object3.getPoints();
    cout << object4.getIndex();
    cout << object4.getPoints();
    
    object.setIndex(1);
    object2.setIndex(2);
    object2.setIndex(5);
    object3.setIndex(5);
    object4.setIndex(5);
    
    
    object.setPoints(10);
    cout << object.getIndex();
    cout << object.getPoints();
    
    object.setPoints(1);
    cout << object.getIndex();
    cout << object.getPoints();
    
    object.setPoints(3);
    cout << object.getIndex();
    cout << object.getPoints();
    
    object.setPoints(-20);
    cout << object.getIndex();
    cout << object.getPoints();
    
    object.setPoints(19);
    cout << object.getIndex();
    cout << object.getPoints();
    
    
    object2.setPoints(10);
    cout << object2.getIndex();
    cout << object2.getPoints();
    
    object2.setPoints(1);
    cout << object2.getIndex();
    cout << object2.getPoints();
    
    object2.setPoints(3);
    cout << object2.getIndex();
    cout << object2.getPoints();
    
    object2.setPoints(-20);
    cout << object2.getIndex();
    cout << object2.getPoints();
    
    object2.setPoints(19);
    cout << object2.getIndex();
    cout << object2.getPoints();
    
    object3.setPoints(10);
    cout << object3.getIndex();
    cout << object3.getPoints();
    
    object3.setPoints(1);
    cout << object3.getIndex();
    cout << object3.getPoints();
    
    object3.setPoints(3);
    cout << object3.getIndex();
    cout << object3.getPoints();
    
    object3.setPoints(-20);
    cout << object3.getIndex();
    cout << object3.getPoints();
    
    object3.setPoints(19);
    cout << object3.getIndex();
    cout << object3.getPoints();
    
    
    
    object4.setPoints(10);
    cout << object4.getIndex();
    cout << object4.getPoints();
    
    object4.setPoints(1);
    cout << object4.getIndex();
    cout << object4.getPoints();
    
    object4.setPoints(3);
    cout << object4.getIndex();
    cout << object4.getPoints();
    
    object4.setPoints(-20);
    cout << object4.getIndex();
    cout << object4.getPoints();
    
    object4.setPoints(19);
    cout << object4.getIndex();
    cout << object4.getPoints();
    
    
    cout << object;
    cout << object2;
    cout << object3;
    cout << object4;
    
    cin >> object;
    cin >> object2;
    cin >> object3;
    cin >> object4;
    
    cout << object;
    cout << object2;
    cout << object3;
    cout << object4;
    
    
    //ANSWER TEST CASES
    Answer a1;
    
    cout << a1.getAttribute();
    cout << a1.getText();
    
    //what parameters do I use?
    //same for set text
    // is it important to get more than one object for answer since there is no non-default constructor?
    
    Attribute a2(4 , 9);
    
    
    a1.setAttribute(a2);
    cout << a1.getAttribute();
    
    a1.setAttribute(object3);
    cout << a1.getAttribute();
    
    a1.setAttribute(object4);
    cout << a1.getAttribute();
    
    a1.setAttribute(object2);
    cout << a1.getAttribute();
    
    a1.setAttribute(object);
    cout << a1.getAttribute();
    cout << a1.getText();
    
    string hello = "Is this working";
    a1.setText(hello);
    
    cout << a1.getText();
    
    string hello1 = "We love EECS sometimes";
    a1.setText(hello1);
    
    cout << a1.getText();
    
    
    string hello2 = "1234countdown";
    a1.setText(hello2);
    
    cout << a1.getText();
    
    cin >> a1;
    
    cout << a2;
    
    //PERSONALITY TEST CASES
    Personality Problems;
    
    Problems.reset();
    
    Problems.adjustPersonality(a2);
    Problems.adjustPersonality(object3);
    Problems.adjustPersonality(object4);
    Problems.adjustPersonality(object2);
    Problems.adjustPersonality(object);
    
    
    //QUESTION TEST CASES
    
    Question pregunta;
    
    cout << pregunta.getNumAnswers();
    cout << pregunta.getQuestionPrompt();
    cout << pregunta.getAnswer(-1);
    cout << pregunta.getAnswer(200);
    cout << pregunta.getAnswer(0);
    cout << pregunta.getAnswer(1);
    cout << pregunta.getAnswer(5);
    cout << pregunta.getAnswer(4);
    
    string question1 = "What is life?";
    pregunta.setQuestionPrompt(question1);
    
    int choosea = -2;
    int chooseb = 0;
    int choosec = 2;
    int choosed = 10;
    int choosee = 11;
    int choosef = 2000;
    
    cout << pregunta.submitAnswer(choosea);
    cout << pregunta.submitAnswer(chooseb);
    cout << pregunta.submitAnswer(choosec);
    cout << pregunta.submitAnswer(choosed);
    cout << pregunta.submitAnswer(choosee);
    cout << pregunta.submitAnswer(choosef);
    
    pregunta.addAnswer(a1);
    
    cin >> pregunta;
    
    cout << pregunta;
    
    
    
    //use getter functions, for private member function, get and setter functions
    // butcher us on style
    
    return 0;
    
}