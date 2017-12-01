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

//ALL DONE