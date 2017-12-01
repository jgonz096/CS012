//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/main.cpp 
/// @brief Assignment/Lab 7 for CS 12 Fall, 2014
///
/// @author Jorge Gonzalez [jgonz096@gmail.com]
/// @date 11/17/14
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
#include "IntVector.h"
#include <iostream>
using namespace std;
int main()
{
    IntVector v(5,7);
    if(v.empty())
    {
        cout << "Your vector is empty." << endl;
        return 0;
    }
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    
    return 0;
}