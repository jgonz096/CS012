//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp/main.cpp 
/// @brief Assignment/Lab <5> for CS 12 <Spring 2014>
///
/// @author <Jorge Gonzalez> [<jgonz096@ucr.edu>]
/// @date <05/14/2014>
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
//  ================== END ASSESSMENT HEADER ===============
#include <cstdlib>
#include "IntVector.h"
using namespace std;
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
//CONSTRUCTORS
IntVector::IntVector()
    : sz(0), cap(0), data(0)
{
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
IntVector::IntVector(unsigned size)
    : sz(size), cap(size)
{
    data = new int[cap];
    for( unsigned i = 0; i < size; ++i )
    {
        data[i] = 0;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
IntVector::IntVector(unsigned size, int value)
    : sz(size), cap(size) 
{
    data = new int[cap];
    for( unsigned i = 0; i < size; ++i )
    {
        data[i] = value;
    }
}
IntVector::~IntVector()
{
    delete[] data;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
//ACCESSORS
unsigned IntVector::size() const
{
    return sz;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
unsigned IntVector::capacity() const
{
    return cap;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
bool IntVector::empty() const
{
    if(size() == 0)
    {
        return true;
    }
    return false;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
const int& IntVector::at(unsigned index) const
{
    if (index >= size())
    {
        exit(1);
    }
    return (data[index]);
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
const int& IntVector::front() const
{
    return data[0];
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
const int& IntVector::back() const
{
    return data[size() - 1];
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::expand()
{
    if(sz != 0)
    {
        int* temp = new int[cap * 2];
        for (int i = 0; i < size(); i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = new int[cap * 2];
        for (int j = 0; j < size(); j++)
        {
            data[j] = temp[j];
        }
        delete[] temp;
    }
    else if (sz == 0)
    {
        sz = 1;
        cap = 1;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::expand(unsigned amount)
{
    if(sz != 0)
    {
        int* temp = new int[cap + amount];
        for (int i = 0; i < size(); i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = new int[cap + amount];
        for (int j = 0; j < size(); j++)
        {
            data[j] = temp[j];
        }
        delete[] temp;
    }
    else if (sz == 0)
    {
        sz = 1;
        cap = 1;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::insert(unsigned index, int value)
{
    int j = 1;
    sz++;
    if(sz > (cap * 2))
    {
        expand(sz - cap);
        cap = sz;
    }
    else if ((sz > cap) && (sz < (cap * 2)))
    {
        expand();
        cap = cap * 2;
    }
    for(int i = index; i < size(); i++)
    {
        data[size() - j] = data[size() - j - 1];
        j++;
    }
    data[index] = value;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::erase(unsigned index)
{
    int j = 0;
    if(index >= size())
    {
        exit(1);
    }
    for (int i = index; i < size(); i++)
    {
        data[index + j] = data[index + j + 1];
        j++;
    }
    sz--;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::push_back(int value)
{
    if( (data == 0) )
    {
        expand();
        cap = cap * 2;
        data = new int[1];
        data[0] = value;
    }
    else
    {
        sz++;
        if( sz > cap)
        {
            expand();
            cap = cap * 2;
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
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::pop_back()
{
    if(empty())
    {
        exit(1);
    }
    else
    sz--;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::clear()
{
    sz = 0;
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::resize(unsigned size)
{
    if( (data == 0) )
    {
        data = new int[size];
        cap = size;
        for(int i = 0; i < size; i++ )
        {
            data[i] = 0;
        }
    }
    if(size < sz)
    {
        sz = size;
        cap = sz;
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
                cap = cap * 2;
            }
            
            if(( cap * 2) < (sz))
            {
                expand( sz - cap );
                cap = sz; 
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
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::resize(unsigned size, int value)
{
    if( (data == 0) )
    {
        data = new int[size];
        cap = size;
        for(int i = 0; i < size; i++ )
        {
            data[i] = value;
        }
    }
    if(size < sz)
    {
        sz = size;
        cap = sz;
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
                cap = cap * 2;
            }
            
            if(( cap * 2) < (sz))
            {
                expand( sz - cap );
                cap = sz; 
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
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
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
            cap = cap * 2;
        }
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
void IntVector::assign(unsigned n, int value)
{
    if (n > sz)
    {
        resize(n);
    }
    for(int i = 0; i < n; ++i)
    {
        data[i] = value;
    }
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
int& IntVector::at(unsigned index)
{
    if (index >= size())
    {
        exit(1);
    }
    return data[index];
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
int& IntVector::front()
{
    if(sz == 0)
    {
        return data[0];
    }
    return data[0];
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
int& IntVector::back()
{
    if(sz == 0)
    {
        return data[0];
    }
    return data[sz - 1];
}