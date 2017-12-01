//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/IntList.cpp 
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
#include <iostream>
#include "IntList.h"
using namespace std;
//===========================================================
//CONSTRUCTORS
//===========================================================
IntList::IntList()
    : head(0), tail(0)
{
}
//===========================================================
//ACCESSORS
//===========================================================
void IntList::display() const
{
    if(head == 0)
    {
        //cout << "List is empty";
        return;
    }
    else
    {
        IntNode* i = head;
        cout << i->data;
        i = i->next;
        while(i != 0)
        {
            cout << " " << i->data;
            i = i->next;
        }
    }
}
//===========================================================
//MUTATORS
//===========================================================
void IntList::push_front(int value)
{
    IntNode* i = new IntNode(value);
    if ((head == 0) && (tail == 0))
    {
        head = i;
        tail = head;
    }
    else
    {
        i->next = head;
        head = i;
    }
}
void IntList::pop_front()
{
    if((head == 0) && (tail = 0))
    {
        return;
    }
    else
    {
        IntNode* i = head;
        head = head->next;
        if(head == 0)
        tail = head;
        delete i;
    }
}
//===========================================================
//DESTRUCTORS
//===========================================================
IntList::~IntList()
{
    while(head != 0)
    {
        pop_front();
    }
}