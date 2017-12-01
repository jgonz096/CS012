//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBaord.cpp 
/// @brief BBoard.cpp/Bulletin Board
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 7, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include "BBoard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
BBoard::BBoard()
    :title("Tony Stark's Amazing Blackboard of Wonders")
{
    current_user.get_username();
    user_list.clear();
    message_list.clear();
}
BBoard::BBoard(const string& ttl)
    :title(ttl)
{
    current_user.get_username();
    user_list.clear();
    message_list.clear();
}
void BBoard::setup(const string& input_file)
{
    ifstream inFS;
    inFS.open(input_file.c_str());
    string a, b;
    while(inFS >> a >> b)
    {
        user_list.push_back(User(a,b));
    }
    inFS.close();
}
void BBoard::login()
{
    string usr, pas;
    cout << "Enter your username ('Q' or 'q' to quit): " << endl;
    cin >> usr;
    if ((usr == "Q") || (usr == "q"))
    {
        cout << "Bye!" << endl;
        exit(0);
    }
    while ((usr != "Q") && (usr != "q"))
    {
        cout << "\nEnter your password: ";
        cin >> pas;
        cout << endl;
        for (int i = 0; i < user_list.size();i++)
        {
            if(user_list.at(i).check(usr, pas))
            {
                current_user = user_list.at(i);
                cout << "Welcome back " << current_user.get_username() << endl;
                return;
            }
        }
        cout << "Invalid Username or Password!" << endl;
        cout << "Enter your username ('Q' or 'q' to quit): " << endl;
        cin >> usr;
    }
    if ((usr == "Q") || (usr == "q"))
    {
        cout << "Bye!" << endl;
        exit(0);
    }
}
void BBoard::run()
{
    char choice = 'A';
    login();
    cout << "Menu" << endl;
    cout << "\t - Dispaly messages ('D' or 'd')" << endl;
    cout << "\t - Add new message ('N' or 'n')" << endl;
    cout << "\t - Quit ('Q' or 'q')" << endl;
    while((choice != 'Q') && (choice != 'q'))
    {
        cin >> choice;
        if ((choice == 'D') || (choice == 'd'))
        {
            if (message_list.empty())
            {
                cout << "Nothing to display" << endl;
                cout << "Menu" << endl;
                cout << "\t - Dispaly messages ('D' or 'd')" << endl;
                cout << "\t - Add new message ('N' or 'n')" << endl;
                cout << "\t - Quit ('Q' or 'q')" << endl;
            }
            else
            {
                display();
                cout << "Menu" << endl;
                cout << "\t - Dispaly messages ('D' or 'd')" << endl;
                cout << "\t - Add new message ('N' or 'n')" << endl;
                cout << "\t - Quit ('Q' or 'q')" << endl;
            }
        }
        else if ((choice == 'N') || (choice == 'n'))
        {
            add_message();
            cout << "Menu" << endl;
            cout << "\t - Dispaly messages ('D' or 'd')" << endl;
            cout << "\t - Add new message ('N' or 'n')" << endl;
            cout << "\t - Quit ('Q' or 'q')" << endl;
        }
        else if ((choice == 'Q') || (choice == 'q'))
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        else
        {
            cout << "Please enter a valid choice master." << endl;
        }
    }
}
void BBoard::display() const
{
    if( message_list.size() < 1 )
    {
        cout << "Nothing to Display." << endl;
    }
    for(int i = 0; i < message_list.size(); i++)
    {
        cout <<"-----------------------------------------------"  << endl;
        cout << "Message #" << i + 1 << ": ";
        message_list.at(i).display();
        cout << endl;
    }
    cout <<"-----------------------------------------------" << endl;
}
void BBoard::add_message()
{
    string subject, body;
    cout << "Enter subject: ";
    cin.ignore();
    getline(cin,subject);
    cout << endl;
    cout << "Enter body: ";
    getline(cin,body);
    cout << endl;
    cout << "Message Recoreded!" << endl;
    Message newMessage(current_user.get_username(),subject,body);
    message_list.push_back(newMessage);
}
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)