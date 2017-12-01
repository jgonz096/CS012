//  =============== BEGIN ASSESSMENT HEADER ================
/// @file User.h 
/// @brief User.h/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User
{
    private:
        string username;
        string password;
    public:
        User(); // creates a user with empty name and password.
        User(const string& uname, const string& pass); // creates a user with given username and password.
        string get_username() const; // returns the username
        bool check(const string& uname, const string& pass) const; // returns true if stored username/password matches the parameters, false otherwise. 
        void set_password(const string& newpass); // sets a new password, but will not be used in the current assignment
};
#endif