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
#ifndef MUSIC_COLLECTION_H
#define MUSIC_COLLECTION_H
#include <fstream>
using namespace std;
class Tune
{
    private:
        string title;
    public:
        Tune();
        Tune(const string &n);
        const string & get_title() const;
};
class Music_collection
{
    private:
        int number;
        int max;
        Tune *collection;
    public:
        Music_collection();
        Music_collection(int n);
        Music_collection(const Music_collection &m);
        bool add_tune(const Tune &t);
        bool set_tune(int index, const Tune &t);
        Music_collection & operator=(const Music_collection &m);
        ~Music_collection();
        friend ostream & operator<<(ostream &out, const Music_collection &m);
};
#endif