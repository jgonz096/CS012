//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<5>/IntVector.cpp 
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
#include <cstdlib>
using namespace std;
//==========================================================
//CONSTRUCTORS
//==========================================================
IntVector::IntVector()
    : sz(0), cap(0), data(0)
{
}
IntVector::IntVector(unsigned size)
    : sz(size), cap(size)
{
    data = new int[sz];
    for(int i = 0; i < sz; i++ )
    {
        data[i] = 0;
    }
}
IntVector::IntVector(unsigned size, int value)
    : sz(size), cap(size)
{
    data = new int[sz];
    for(int i = 0; i < sz; i++ )
    {
        data[i] = value;
    }
}
//==========================================================
//PUBLIC ACCESSOR FUNCTIONS
//==========================================================
unsigned IntVector::size() const
{
    return sz;
}
unsigned IntVector::capacity() const
{
    return cap;
}
bool IntVector::empty( ) const
{
    if(sz == 0)
    return true;
    return false;
}
const int& IntVector::at( unsigned index ) const
{
    if (index >= sz)
    exit(1);
    return data[index];
}