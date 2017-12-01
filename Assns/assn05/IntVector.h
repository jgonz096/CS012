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
    private:
        unsigned sz;
        unsigned cap;
        int* data;
        void expand();
        void expand(unsigned amount);
    public:
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int& at(unsigned index) const;
        int& at(unsigned index);
        void insert(unsigned index,int value);
        void erase(unsigned index);
        const int& front() const;
        int& front();
        const int& back() const;
        int& back();
        void assign(unsigned n,int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size);
        void resize(unsigned size,int value);
        void reserve(unsigned n);
};
#endif