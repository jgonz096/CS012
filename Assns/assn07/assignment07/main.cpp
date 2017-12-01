//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBoard.cpp 
/// @brief assn7/bulletin board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date December 12, 2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Ali Mohammadkhan
///
///  @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include "BBoard.h"
using namespace std;
int main(int argc, char **argv)
{
    BBoard bb;
    string userfile, datafile;
    if(argc != 3)
    {
       cout << "ERROR: Invalid program call." << endl;
       cout << "Usage: <program_name> userfile datafile" << endl;
       return 1;
    }
    if(!bb.load_users(userfile))
    {
       cout << "ERROR: Cannot load users from " << userfile << endl;
       return 1;
    }
    if (!bb.load_messages(datafile))
    {
       cout << "ERROR: Cannot load messages from " << datafile << endl;
       return 1;
    }
    bb.login();
    bb.run();
    if(!bb.save_messages(datafile))
    {
       cout << "ERROR: Cannot save messages to " << datafile << endl;
       return 1;
    }
    return 0;
}