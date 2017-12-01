//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<5>/IntVector.h
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
#include <iostream>
using namespace std;
#ifndef INTVECTOR_H
#define INTVECTOR_H
class IntVector
{
    unsigned sz;
    unsigned cap;
    int* data;
    public:
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at( unsigned index ) const;
};
#endif