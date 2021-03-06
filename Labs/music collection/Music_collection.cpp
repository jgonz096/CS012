//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp/main.cpp 
/// @brief Assignment/Lab <10> for CS 12 <Spring 2014>
///
/// @author <Jorge Gonzalez> [<jgonz096@ucr.edu>]
/// @date <06/04/2014>
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
#include "Music_collection.h"
#include <iostream> 
using namespace std;
Tune::Tune()
    : title("")
{
}
Tune::Tune(const string &n)
    : title(n)
{
}
const string& Tune::get_title() const
{
    return title;
}
Music_collection::Music_collection()
    : number(0), max(100)
{
    collection = new Tune[max];
}
Music_collection::Music_collection(int n)
    : number(0), max(n)
{
    collection = new Tune[max];
}
Music_collection::Music_collection(const Music_collection &m)
{
    collection = new Tune[m.max];
    number = m.number;
    max = m.max;
    for(int i = 0; i < number; i++)
    {
        collection[i] = m.collection[i];
    }
}
bool Music_collection::add_tune(const Tune &t)
{
    if((number + 1) > max)
    {
        return false;
    }
    else 
    {
        collection[number] = t;
        number++;
        return true;
    }
}
bool Music_collection::set_tune(int index, const Tune &t)
{
    if(index < number)
    {
        collection[index] = t;
        return true;
    }
    return false;
}
Music_collection& Music_collection::operator=(const Music_collection &m)
{
    if(this == &m)
    {
        ; // does nothing at all lol
    }
    else
    {
        delete[] collection;
        collection = new Tune[m,max];
        number = m.number;
        max = m.max;
        for(int i = 0; i < number; i++)
        {
            collection[i] = m.collection[i];
        }
    }
    return *this;
}
Music_collection::~Music_collection()
{
    delete[] collection;
}
ostream & operator<<(ostream &out, const Music_collection &m)
{
    for (int i = 0; i < m.number; i++)
    {
        out << m.collection[i].get_title() << endl;
    }
    return out;
}