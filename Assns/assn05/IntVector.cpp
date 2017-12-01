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
bool IntVector::empty() const
{
    if(sz == 0)
    return true;
    return false;
}
const int& IntVector::at( unsigned index ) const
{
    if (index >= sz)
    {
        exit(1);
    }
    return data[index];
}
const int& IntVector::front() const
{
    return data[0];
}
const int& IntVector::back() const
{
    return data[sz - 1];
}
//==========================================================
//DESTRUCTOR
//==========================================================
IntVector::~IntVector()
{
    delete[] data;
}
//==========================================================
//PRIVATE HELPER FUNCTIONS
//==========================================================
void IntVector::expand()
{
    if(cap == 0)
    {
        sz = 1;
        cap = 1;
        return;
    }
    else
    {
        cap = cap * 2;
        int* temp = new int[cap];
        for(int i = 0; i < sz; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = new int[cap];
        for(int j = 0; j < sz; j++)
        {
            data[j] = temp[j];
        }
        delete[] temp;
        
    }
}
void IntVector::expand(unsigned amount)
{
    if(cap == 0)
    {
        sz = 1;
        cap = 1;
        return;
    }
    else
    {
        cap = cap + amount;
        int* temp = new int[cap];
        for(int i = 0; i < sz; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = new int[cap];
        for(int j = 0; j < sz; j++)
        {
            data[j] = temp[j];
        }
        delete[] temp;
        
    }
}
//==========================================================
//MUTATORS
//==========================================================
void IntVector::clear()
{
    sz = 0;
}
int& IntVector::at(unsigned index)
{
    if (index >= sz)
    {
        exit(1);
    }
    return data[index];
}
int& IntVector::front()
{
    if(sz == 0)
    {
        exit(1);
    }
    return data[0];
}
int& IntVector::back()
{
    if(sz == 0)
    {
        exit(1);
    }
    return data[sz - 1];
}
void IntVector::pop_back()
{
    if(sz == 0)
    {
        exit(1);
    }
    sz--;
}
void IntVector::push_back(int value)
{
    if( (data == 0) )
    {
        expand();
        data = new int[1];
        data[0] = value;
    }
    else
    {
        sz++;
        if( sz > cap)
        {
            expand();
        }
        int* temp = new int[cap];
        for(int i = 0; i < sz; ++i)
        {
            temp[i] = data[i];
        }
        temp[sz - 1] = value;
        delete[] data;
        data = new int[cap];
        for(int j = 0; j < sz; j++)
        {
            data[j] = temp[j];
        }
        delete[] temp;
    }
}
void IntVector::erase(unsigned index)
{
    if(index >= sz)
    {
        exit(1);
    }
    for(int i = index; i < sz - 1; i++)
    {
        data[i] = data[i + 1];
    }
    pop_back();
}
void IntVector::insert(unsigned index,int value)
{
    if(index > sz)
    {
        exit(1);
    }
    if (sz == 0)
    {
        expand();
        push_back(value);
        return;
    }
    if(index == sz - 1)
    {
        push_back(value);
        return;
    }
    sz++;
    if(sz > cap)
    {
        expand();
    }
    for(int i = sz - 1; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
}
void IntVector::resize(unsigned size)
{
    if(data == 0)
    {
        sz = size;
        data = new int[sz];
        cap = sz;
        for(int i = 0; i < sz; i++)
        {
            data[i] = 0;
        }
        return;
    }
    else if(size < sz)
    {
        sz = size;
        return;
    }
    else if(size == sz)
    {
        return;
    }
    else
    {
        int temp = sz;
        sz = size;
        if( sz > cap)
        {
            if((sz > cap) && ((sz) <  (cap * 2)))
            {
                expand();
            }
            
            if(( cap * 2) < (sz))
            {
                expand( sz - cap );
            }
        }
        if(sz > temp)
        {
            for(int i = 1; i <= (sz - temp); i++ )
            {
                data[sz - i] = 0;
            }
        }
    }
}
void IntVector::resize(unsigned size, int value)
{
    int i = 0;
    int j = (size - sz);
    if(data == 0)
    {
        sz = size;
        data = new int[sz];
        cap = sz;
        for(int i = 0; i < sz; i++)
        {
            data[i] = value;
        }
        return;
    }
    else if(size < sz)
    {
        sz = size;
        return;
        
    }
    else if(size == sz)
    {
        return;
    }
    else
    {
        int temp = sz;
        sz = size;
        if( sz > cap)
        {
            if((sz > cap) && ((sz) <  (cap * 2)))
            {
                expand();
            }
            
            if(( cap * 2) < (sz))
            {
                expand( sz - cap );
            }
        }
        if(sz > temp)
        {
            for(int i = 1; i <= (sz - temp); i++ )
            {
                data[sz - i] = value;
            }
        }
    }
}
void IntVector::reserve(unsigned n)
{
    if(n > sz)
    {
        if(n > (cap * 2))
        {
            expand(n - cap);
            cap = n;
        }
        else 
        {
            expand();
        }
    }
}
void IntVector::assign(unsigned n, int value)
{
    reserve(n);
    sz = n;
    for(int i = 0; i < n; i++)
    {
        data[i] = value;
    }
}