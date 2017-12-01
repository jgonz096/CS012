//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBaord.h 
/// @brief BBoard.h/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef BBOARD_H
#define BBOARD_H
#include <string>
#include "User.h"
#include "Message.h"
#include <vector>
using namespace std;
class BBoard
{
    string title; //title of the board initialized by the constructor.
    vector<User>user_list; //list of members, initially empty then populated via setup()
    User current_user; // user who is currently logged in, initialized by contructor to the default user, then set via login()
    vector<Message>message_list; // list of messages, initially empty
    void display() const; // used by interface function run, it displays all messages in message_list
    void add_message(); // used by function run. asks for a message from input
    public:
        BBoard(); // default constructor that creates a board with a default title, empty user and message lists, and teh "default" User
        BBoard(const string &ttl); // Same as above except that it sets the title of board
        void setup(const string& input_file); // imports all the authorized users from an input file, storing them as User objects in the vector user_list, where the name of the input file is passed in.
        void login(); // asks for and validates current user/password
        void run(); // function contains main loop of the board
};
#endif