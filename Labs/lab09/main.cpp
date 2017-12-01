//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/main.cpp 
/// @brief Assignment/Lab 9 for CS 12 Fall, 2014
///
/// @author Jorge Gonzalez [jgonz096@gmail.com]
/// @date 12/01/14
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
#include <cstdlib>
using namespace std;
void reverse(string& x)
{
    if((x.size() == 0) || (x.size() == 1))
    {
        return;
    }
    else
    {
        string y = x.substr(1,x.size() - 2);
        reverse(y);
        x = (x.at(x.size() - 1)) + y + x.at(0);
    }
}
int main()
{
    string x = "Iron Man";
    cout << "here is your string not reversed: " << x << endl;
    reverse(x);
    cout << "now here is your string reversed: " << x << endl;
    return 0;
}