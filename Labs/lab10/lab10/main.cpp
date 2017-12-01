//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab10/main.cpp
/// @brief Assignment/Lab 10 for CS 12 Fall, 2014
///
/// @author Jorge Gonzalez [jgonz096@gmail.com]
/// @date 12/09/14
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
#include "Music_collection.h"
using namespace std;
main()
{
    //create a few Tune objects to use later on;
    Music_collection A;
    //   add a few tunes to A;
    Music_collection B(A); 
    //change a Tune in B using set_tune function;
    Music_collection C;
    C = B; 
    //add a Tune to B; 
    //change a Tune in C using set_tune function;
    //print A,B,C; 
    return 0;
}
