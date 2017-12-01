//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBoard.h 
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
#include <vector>
#ifndef BBOARD_H
#define BBOARD_H
#include "Message.cpp"
#include "User.cpp"
class BBoard
{
    private:
        string title;
        vector<User>user_list;
        User current_user;
        vector<Message>message_list;
        void add_user(istream &infile, const string &name, const string &pass);
        bool user_exists(const string &name, const string &pass, int i) const; 
        void display() const; 
        void display2() const;
        void add_message(); 

    public: 
        BBoard();
        BBoard(const string& ttl);
        void setup(const string& input_file);
        void login();
        void run();
};
#endif