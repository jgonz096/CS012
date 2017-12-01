//  =============== BEGIN ASSESSMENT HEADER ================
/// @file IntList.h
/// @brief Lab 8
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 21, 2014
//  ================== END ASSESSMENT HEADER ==============
#ifndef INTLIST_H
#define INTLIST_H
using namespace std;
struct IntNode
{
    int data;
    IntNode* next;
    IntNode(int data) : data(data), next(0){}
};
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
class IntList
{
    IntNode* head;
    IntNode* tail;
    public:
        IntList();
        ~IntList();
        void display() const;
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void select_sort();
        void insert_sorted(int value);
        void remove_duplicates();
};
#endif