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
#include <vector>
#ifndef BBOARD_H
#define BBOARD_H
#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"
class BBoard
{
    private:
        string title;
        vector<User>user_list;
        const User* current_user;
        vector<Message*>message_list;
        void add_user(const string &name, const string &pass);
        bool user_exists(const string &name, const string &pass, int i) const; 
        void display() const; 
        // void add_message(); 
        void add_topic();
        void add_reply();
        const User *get_user(const string &name,const string &pw) const;

    public: 
        BBoard();
        BBoard(const string& ttl);
        ~BBoard();
        bool load_users(const string &userfile);
        bool load_messages(const string &datafile);
        bool save_messages(const string &datafile);
        void login();
        void run();
};
#endif