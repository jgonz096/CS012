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
#include "User.h"
using namespace std;
//===============================================
//CONSTRUCTORS
//===============================================
User::User()
    : username(""), password("")
{
}
User::User(const string& uname, const string& pass)
    : username(uname), password(pass)
{
}
//===============================================
//public member functions
//===============================================
bool User::check(const string &uname, const string &pass) const
{
    if(uname == "")
    {
        return false;
    }
    else if ((uname == username) && (pass == password))
    {
        return true;
    }
    else
    return false;
}
void User::set_password(const string &newpass)
{
    password = newpass;
}
string User::get_username() const
{
    return username;
}

//ALL DONE