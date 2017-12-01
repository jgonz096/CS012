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
#include <iostream>
#include "Music_collection.h"
using namespace std;
int main()
{
    Music_collection one;
    Music_collection two(10);
    Tune alpha("Test 1");
    Tune beta("Test 2");
    Tune cappa("Test 3");
    Tune delta("Test 4");
    one.add_tune(alpha);
    cout << one << endl;
    one.add_tune(beta);
    cout << one << endl;
    two.add_tune(beta);
    two.add_tune(cappa);
    two.add_tune(delta);
    cout << two << endl;
    two.set_tune(0, alpha);
    two.set_tune(1, delta);
    cout << two << endl;
    two = one;
    cout << one << endl;
    cout << two << endl;
    Music_collection Gamma = two;
    cout << Gamma << endl;
    return 0;
}