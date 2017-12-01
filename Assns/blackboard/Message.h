//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Message.h 
/// @brief Message.h/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
using namespace std;
class Message
{
    private:
        string author;
        string subject;
        string body;
    public:
        Message(); // default constructor
        Message(const string& athr, const string& sbjct, const string& body); // constructor w/parameters
        void display() const; // displays message in given format.
};
#endif