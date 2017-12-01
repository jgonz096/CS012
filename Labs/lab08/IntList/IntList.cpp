//  =============== BEGIN ASSESSMENT HEADER ================
/// @file IntList.cpp 
/// @brief Lab 8
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 21, 2014
//  ================== END ASSESSMENT HEADER ==============
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
#include "IntList.h"
#include <iostream>
using namespace std;
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
IntList::IntList()
    : head(0), tail(0)
{
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
// IntList::IntList(const IntList &x)
// {
    
// }
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
IntList::~IntList()
{
    while(head != 0)
    {
        pop_front();
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::display() const
{
    IntNode* current = head;
    if(head == 0)
    {
        return;
    }
    else
    {
        cout << current->data;
        current = current->next;
        while(current != 0)
        {
            cout << " " << current->data;
            current = current->next;
        }
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::push_front(int value)
{
    IntNode* temp = new IntNode(value);
    if (head == 0)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::push_back(int value)
{
    IntNode* temp = new IntNode(value);
    if(head == 0)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::pop_front()
{
    if(head != 0)
    {
        IntNode* temp = head;
        head = head->next;
        if(head == 0)
        {
            tail = 0;
        }
        delete temp;
    }
    
    else if (head == 0)
    {
        return;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::select_sort()
{
    IntNode *h = head, *i, *j;
    for(i = h; ((i != 0) && (i->next != 0)); i = i->next)
    {
        IntNode *min;
        min = i;
        for(j = i->next; j != 0; j = j->next)
        {
            if(j->data < min->data)
            {
                min=j;
            }
        }
        if(min != i)
        {
            int temp;
            temp = min->data;
            min->data = i->data;
            i->data = temp;
        }
    }
    head = h;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::insert_sorted(int value)
{
    if (head == 0) 
    { 
        push_front(value);
    } 
    else if(head == tail)
    {
        
        if(head -> data > value)
        {
            push_front(value);
            return;
        }
        
        else
        {
            push_back(value);
            return;
        }
        
    }
    else if(head == tail ) 
    {
        push_back( value ); 
    } 
    else if( value < head -> data) 
    {
        push_front(value);  
    } 
    else 
    {
        IntNode* tracker = head;  
        while(tracker->next != 0) 
    	{  
    		if( tracker -> next -> data > value ) 
    		{
    			break;     
    		}
    		tracker = tracker -> next;  
    	}
        IntNode *temp = new IntNode(value);
        temp -> next = tracker -> next;
        tracker -> next = temp;
        if ( value >= tail -> data )
        {
            push_back(value);
            return;
        }
    }           
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntList::remove_duplicates()
{
    IntNode *current, *previous, *hold, *temp;
    if((head == 0) || (head == tail))
    { 
        return;
    }
    current = head->next;
    previous = head;
    while(current != 0)
    {
        hold = head;
        while(hold != current)
        {
            if(hold->data == current->data)
            {
                temp = current;
                current = current->next;
                previous->next = current;
                delete temp;
                break;
            }
            hold = hold->next;
        }
        if(hold == current)
        {
            current = current->next;
            previous = previous->next;
        }
    }
    tail = previous;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
//http://www.nexusmods.com/newvegas/mods/52140/? the sneaking suit