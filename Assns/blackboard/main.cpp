//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief main.cpp/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <fstream>
#include "BBoard.h"
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    string title = "Tony Stark's Marvelous Board of Heroes";
    BBoard Blackboard(title);
    string input_file = argv[1];
    cout << "Welcome to " << title <<  endl;
    Blackboard.setup(input_file);
    Blackboard.run();
    return 0;
}