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
        // cout << "List is empty";
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
void IntList::push_back(int value)
{
    IntNode* i = new IntNode(value);
    if ((head == 0) && (tail == 0))
    {
        head = i;
        tail = head;
    }
    else
    {
        tail->next = i;
        tail = i;
    }
}
void IntList::pop_front()
{
    if((head == 0) && (tail = 0))
    {
        return;
    }
    if(head == tail)
    {
        IntNode *i = head;
        head = 0;
        tail = 0;
        delete i;
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
void IntList::select_sort()
{
    if((head == 0) && (tail == 0))
    {
        return;
    }
    else
    {
        IntNode *i = head;
        // cout << "i: " << i->data << endl;
        IntNode *small = 0;
        IntNode *j = 0;
        while((i != 0) && (i->next != 0))
        {
            small = i;
            j = i->next;
            while(j != 0)
            {
                if(j->data < small->data)
                {
                    small = j;
                }
                // cout << "j: " << j->data << endl;
                j = j->next;
            }
            if(small != i)
            {
                int k = small->data;
                small->data = i->data;
                i->data = k;
            }
            // cout << "i data: " << i->data << endl;
            // cout << "small: " << small->data << endl;
            // cout << "j: " << j << endl;
            i = i->next;
            // cout << "i data: " << i->data << endl;
        }
        // i = 0;
        // j = 0;
        // small = 0;
        // delete i;
        // delete j;
        // delete small;
        display();
    }
}
void IntList::insert_sorted(int value)
{
    if((head == 0) && (tail == 0))
    {
        push_front(value);
    }
    else if(head == tail)
    {
        if(head->data > value)
        {
            push_front(value);
        }
        else if(head->data <= value)
        {
            push_back(value);
        }
    }
    else
    {
        if(value <= head->data)
        {
            push_front(value);
            return;
        }
        IntNode *i = head;
        IntNode *j = head->next;
        while((j != 0))
        {
            if((i->data <= value) && (j->data >= value))
            {
                IntNode *k = new IntNode(value);
                i->next = k;
                k->next = j;
                return;
            }
            i = i->next;
            j = j->next;
        }
        j = tail;
        if((j == tail) && (j->data < value))
        {
            push_back(value);
            return;
        }
    }
    return;
}
void IntList::remove_duplicates()
{
    IntNode *i, *j, *check, *temp;
    if((head == 0) && (tail == 0))
    { 
        return;
    }
    if(head == tail)
    {
        return;
    }
    i = head->next;
    j = head;
    while(i != 0)
    {
        check = head;
        while(check != i)
        {
            if(check->data == i->data)
            {
                temp = i;
                i = i->next;
                j->next = i;
                delete temp;
                break;
            }
            check = check->next;
        }
        if(check == i)
        {
            i = i->next;
            j = j->next;
        }
    }
    tail = j;
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