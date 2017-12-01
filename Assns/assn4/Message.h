//  =============== BEGIN ASSESSMENT HEADER ================
/// @file message.h 
/// @brief assn4/bulletin board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date November 9, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
using namespace std;
class Message
{
    private:
      string author;
      string subject;
      string body;
    public:
      Message();
      Message(const string &athr, 
              const string &sbjct, 
              const string &body);
      void display() const;
};
#endif