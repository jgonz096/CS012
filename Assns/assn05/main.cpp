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
    cout << "Current size and capacity" << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << "First and last values are" << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << "Vector looks like" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.push_back(10);
    cout << "After push back" << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << "First and last values are" << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << "Vector looks like" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.pop_back();
    cout << "After pop back" << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << "First and last values are" << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << "Vector looks like" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.insert(5,51);
    cout << "After insertion" << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << "First and last values are" << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << "Vector looks like" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.resize(45,47);
    cout << "After resize" << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << "First and last values are" << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << "Vector looks like" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    
    
    return 0;
}