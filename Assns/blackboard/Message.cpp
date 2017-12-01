//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Message.cpp 
/// @brief Message.cpp/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include "Message.h"
using namespace std;
Message::Message()
    : author(""), subject(""), body("")
{
}
Message::Message(const string& athr, const string& sbjct, const string& body)
    : author(athr), subject(sbjct), body(body)
{
}
void Message::display() const
{
    cout << "subject: " << subject << endl;
    cout << "from " << author << ": " << body << endl;
}