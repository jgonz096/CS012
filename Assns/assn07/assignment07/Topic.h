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
#ifndef TOPIC_H
#define TOPIC_H
#include "Message.h"
#include <iostream>
using namespace std;
class Topic : public Message
{
    public:
        Topic();
        Topic(const string &athr, const string &sbjct, const string &body, unsigned id);
        virtual bool is_reply() const;
        virtual string to_formatted_string() const;
};
#endif