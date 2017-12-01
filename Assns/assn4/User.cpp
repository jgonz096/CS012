//  =============== BEGIN ASSESSMENT HEADER ================
/// @file User.cpp 
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
string User::get_username() const
{
    return username;
}
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
//void User::set_password(const string &newpass);
