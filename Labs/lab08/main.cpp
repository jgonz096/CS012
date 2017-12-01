//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/main.cpp 
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
int main()
{
    IntList list;
    list.display();
    cout << endl;
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    list.push_front(9);
    cout << "current list: ";
    list.display();
    cout << endl;
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    cout << "current list: ";
    list.display();
    cout << endl;
    return 0;
}