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
#include "Reply.h"
#include <iostream>
#include <sstream>
using namespace std;
Reply::Reply()
    : Message()
{
}
Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id)
    : Message(athr, sbjct, body, id)
{
}
bool Reply::is_reply() const
{
    return true;
}
string changeIntToString1(const int& x)
{
    ostringstream change;
    change << x;
    string y = change.str();
    return y;
}
string Reply::to_formatted_string() const
{
    string output = "<begin reply>\n:id: " + changeIntToString1(id) + "\n:subject: " + subject + "\n:from: " + author;
    // cout << "<begin reply>" << endl;
    // cout << ":id: " << id << endl;
    // cout << ":subjuect: " << subject << endl;
    // cout << ":from: " << author << endl;
    if(child_list.size() != 0)
    {
        output += "\n:children:";
        // cout << ":children: "
        for (int i = 0; i < child_list.size(); i++)
        {
            output += " " + changeIntToString1(child_list.at(i)->get_id());
        }
    }
    output += "\n:body: " + body + "\n<end>\n";
    return output;
}