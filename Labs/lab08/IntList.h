//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/IntList.h
/// @brief Assignment/Lab 8 for CS 12 Fall, 2014
///
/// @author Jorge Gonzalez [jgonz096@gmail.com]
/// @date 11/22/14
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Ali Mohammadkhan
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#ifndef INTLIST_H
#define INTLIST_H
struct IntNode
{
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};
class IntList
{
    private:
        IntNode* head;
        IntNode* tail;
    public:
        IntList();
        ~IntList();
        void display() const;
        void push_front(int value);
        void pop_front();
};
#endif