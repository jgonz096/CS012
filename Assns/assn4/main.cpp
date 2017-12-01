//  =============== BEGIN ASSESSMENT HEADER ================
/// @file User.h 
/// @brief assn4/bulletin board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date November 9, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include "BBoard.cpp"
using namespace std;
int main(int argc, char* argv[])
{
    string title = "Militaires sans Frontieres Military Blackboard";
    BBoard Blackboard(title);
    string input_file = argv[1];
    cout << "Welcome to " << title <<  endl;
    Blackboard.setup(input_file);
    Blackboard.run();
    return 0;
}