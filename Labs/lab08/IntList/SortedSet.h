//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<5>/main.cpp
/// @brief Assignment/Lab <8> for CS 12 <Spring 2014>
///
/// @author <Jorge Gonzalez> [jgonz096@ucr.edu]
/// @date <4 June 2104>
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
//  ================== END ASSESSMENT HEADER
#include "IntList.h"
using namespace std;
class SortedSet : public IntList
{
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        SortedSet in(int data);
        // SortedSet & operator |;
        // SortedSet  & operator &;
        void add(int data);
        void push_front(int data);
        void push_back(int data);
        void insert_sorted(int data);
        // SortedSet & operator |=;
        // SortedSet & operator &=;
};