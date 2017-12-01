//  =============== BEGIN ASSESSMENT HEADER ================
/// @file User.cpp 
/// @brief User.cpp/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include "User.h"
#include <string>
#include <iostream>
using namespace std;
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
bool User::check(const string& uname, const string& pass) const
{
    if(((username == uname) && (password == pass)) && !((uname == "") && (pass == "")) && !((uname == "Q") && (uname == "q")))
    {
        return true;
    }
    return false;
}
void User::set_password(const string& newpass)
{
    password = newpass;
}