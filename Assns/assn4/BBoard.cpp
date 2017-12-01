//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBoard.cpp 
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
#include <fstream>
#include <vector>
#include <cstdlib>
#include "BBoard.h"
using namespace std;
//==========================================================
//CONSTRUCTORS
//==========================================================
BBoard::BBoard()
    : title("Militaires Sans Frontieres Message Board")
{
    user_list.clear();
    message_list.clear();
    current_user.get_username();
}
BBoard::BBoard(const string &ttl)
    : title(ttl)
{
    user_list.clear();
    message_list.clear();
    current_user.get_username();
}
//==========================================================
//PRIVATE MEMBER FUNCTIONS
//==========================================================
bool BBoard::user_exists(const string &name, const string &pass, int pos) const
{
    if(user_list.at(pos).check(name, pass))
    {
        return true;
    }
    return false;
}
void BBoard::add_message()
{
    string sbjct, bdy;
    cout << "Enter subject: ";
    cin.ignore();
    getline(cin,sbjct);
    cout << endl;
    cout << "Enter body: ";
    getline(cin,bdy);
    cout << endl;
    cout << "Message Recoreded!" << endl;
    Message newMessage(current_user.get_username(),sbjct,bdy);
    message_list.push_back(newMessage);
}
void BBoard::display() const
{
    if(message_list.size() == 0)
    {
        cout << "Nothing to Display." << endl;
    }
    for(int i = 0; i < message_list.size(); i++)
    {
        cout << "-----------------------------------------------------"  << endl;
        cout << "Message #" << i + 1 << ": ";
        message_list.at(i).display();
        cout << endl;
    }
    cout << "-----------------------------------------------------" << endl;
}
void BBoard::display2() const
{
    cout << "Menu" << endl;
    cout << "\t - Dispaly messages ('D' or 'd')" << endl;
    cout << "\t - Add new message ('N' or 'n')" << endl;
    cout << "\t - Quit ('Q' or 'q')" << endl;
}
//==========================================================
//PUBLIC MEMBER FUNCTIONS
//==========================================================
void BBoard::setup(const string &input_file)
{
    ifstream File;
    File.open(input_file.c_str());
    string n, p;
    while(File >> n >> p)
    {
        user_list.push_back(User(n,p));
    }
    File.close();
}
void BBoard::login()
{
    string usr, pas;
    cout << "Enter your username ('Q' or 'q' to quit): " << endl;
    cin >> usr;
    while ((usr != "Q") && (usr != "q"))
    {
        cout << "\nEnter your password: ";
        cin >> pas;
        cout << endl;
        for (int i = 0; i < user_list.size();i++)
        {
            if(user_exists(usr,pas,i))
            {
                current_user = user_list.at(i);
                cout << "Welcome back " << current_user.get_username() << endl;
                return;
            }
        }
        cout << "Invalid Username/Password!" << endl;
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
    char choice;
    login();
    cout << "Menu" << endl;
    display2();
    while((choice != 'Q') && (choice != 'q'))
    {
        cin >> choice;
        if ((choice == 'D') || (choice == 'd'))
        {
            if (message_list.empty())
            {
                cout << "Nothing to display" << endl;
                display2();
            }
            else
            {
                display();
                display2();
            }
        }
        else if ((choice == 'N') || (choice == 'n'))
        {
            add_message();
            display2();
        }
        else if ((choice == 'Q') || (choice == 'q'))
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        else
        {
            cout << "Please enter a valid choice my young padowan." << endl;
        }
    }
}