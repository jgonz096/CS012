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
using namespace std;
#ifndef USER_H
#define USER_H
class User
{
    private:
      string username;
      string password;
    public:
      User();
      User(const string& uname, const string& pass);
      string get_username() const;
      bool check(const string &uname, const string &pass) const;
      void set_password(const string &newpass);
};
#endif
