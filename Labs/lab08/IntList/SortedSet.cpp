//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<5>/main.cpp
/// @brief Assignment/Lab <8> for CS 12 <Spring 2014>
///
/// @author <Jorge Gonzalez> [jgonz096@ucr.edu]
/// @date <4 June 2014>
///
/// @par Enrollment Notes
///     Lecture Section: <001>
/// @par
///     Lab Section: <001>
/// @par
///     TA: <Juan Leon>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER===============
#include "SortedSet.h"
using namespace std;
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
SortedSet::SortedSet()
{
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
SortedSet::SortedSet(const SortedSet & list) //fixme?
{
    SortedSet curr_1 = list.head;
    head = new SortedSet(curr_1 -> data); 
    //may need to set value in tail
    IntNode curr_2 = head -> next;
    while(curr_1->next != 0)
    {
        curr_2->data = curr_1->data;
        curr_2.push_back(curr_1->next->data);
        curr_1 = curr_1->next;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
SortedSet::SortedSet(const IntList & list)
 : IntList(list)
{
    select_sort();
    remove_duplicates();
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
SortedSet::~SortedSet()
{
    //fixme maybe
   clear();
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
bool SortedSet::in(int data) const // fixme?
{
    if(head == 0)
    {
        return false;
    }
    if( head == tail )
    {
        if (head -> data == data)
        {
            return true;
        }
        return false;
    }
    else if( (head -> data == data) || (tail->data == data) )
    {
        return true;
    }
    else
    {
        IntNode* tracker = head;
        while(ttracker->next != 0)
        {
            if(tracker->next->data == data)
            {
                return true;
            }
            tracker = tracker->next;
        }
    }
    return false;
}
void SortedSet::add(int data)
{
    if(!in(data))
    {
        insert_sorted(data);
    }
    return;
}
void SortedSet::push_front(int data);
void SortedSet::push_back(int data);
void SortedSet::insert_sorted(int data)
{
    if(head == 0)
    {
        add(data);
        return;
    }
    if(head == tail)
    {
        if(head->data > value)
        {
            add(data);
            return;
        }
        else if(head->data < value)
        {
            add(data);
            return;
        }
    }
    else
    {
        
        IntNode *i = head;
        IntNode *j;
        IntNode *temp;
        for(j = head->next; j->next != 0; j = j->next)
        {
            if((value < j->data) && (value < i->data))
            {
                add(data);;
                return;
            }
            else if((value < j->data) && (value > i->data))
            {
                temp = new IntNode(value);
                i->next = temp;
                temp->next = j;
                return;
            }
            else if((value > j->data) && (value > i->data))
            {
                if(j->next != 0)
                {
                    i = i->next;
                }
                else
                {
                    add(data);;
                    return;
                }
            }
            else if((value > j->data) && (value > i->data) && (j->next == 0))
            {
                add(data);
                return;
            }
        }
        if((value > j->data) && (value > i->data) && (j->next == 0))
        {
            add(data);
            return;
        }
    }
}
/*const SortedSet & SortedSet::operator|(const SortedSet & list) const
{
    
    SortedSet temp = this;
    SortedSet curr = list;
    
    while( curr -> next != 0 )
    {
        temp.add(curr -> data)
        curr = curr -> next;
    }
    
    temp.remove_duplicates();
    
    return temp;
    
}

const SortedSet & SortedSet::operator&(const SortedSet & list) const
{
}

SortedSet & SortedSet::operator|=(const SortedSet &)
{
    
    SortedSet curr = list;
    
    while( curr -> next != 0 )
    {
        this.add(curr -> data)
        curr = curr -> next;
    }
    
    temp.remove_duplicates();
    
    return this;
    
}

SortedSet & SortedSet::operator&=(const SortedSet &)
{
    
    SortedSet curr = list;
    
    while( curr -> next != 0 )
    {
        this.add(curr -> data)
        curr = curr -> next;
    }
    
    return this;
    
}*/