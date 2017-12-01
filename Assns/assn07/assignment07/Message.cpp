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
#include "Message.h"
using namespace std;
//=========================================================================
//CONSTRUCTORS
//=========================================================================
Message::Message()
    : author(""), subject(""), body(""), id(0)
{
}
Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id)
    : author(athr), subject(sbjct), body(body), id(id)
{
}
//=========================================================================
//DESTRUCTORS
//=========================================================================
Message::~Message()
{
    while(child_list.size() != 0)
    {
        child_list.pop_back();
    }
}
//=========================================================================
//PUBLIC MEMBER FUNCTIONS
//=========================================================================
bool Message::is_reply() const
{
    return true;
}
string Message::to_formatted_string() const
{
    for(int i = 0; i < child_list.size(); i++)
    {
        if(child_list.at(i)->is_reply())
        {
            child_list.at(i)->to_formatted_string();
        }
        else
        child_list.at(i)->to_formatted_string();
    }
}
unsigned Message::get_id() const
{
    return id;
}
const string& Message::get_subject() const
{
    return subject;
}
void Message::add_child(Message *child)
{
    child_list.push_back(child);
}
void indent(unsigned indentation)
{
    for (unsigned i = 0; i < indentation; i++) 
    {
        cout << "  ";
    }
}
void Message::print(unsigned indentation) const
{
    cout << endl;
    indent(indentation);
    cout << "Message #" << id << ": " << subject << endl;
    indent(indentation);
    cout << "from " << author << ": ";
    for (unsigned j = 0; j < body.size(); j++) 
    {
        cout << body.at(j);
        if (body.at(j) == '\n') 
        {
            indent(indentation);
        }
    }
    cout << endl;
    for (unsigned i = 0; i < child_list.size(); i++) 
    {
        static_cast<Message*>(child_list.at(i))->print(indentation + 1);
    }
}
void Message::display() const
{
    cout << "subject: " << subject << endl;
    cout << "from " << author << ": " << body << endl;
}