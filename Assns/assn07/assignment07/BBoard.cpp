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
#include <sstream>
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
    current_user = 0;
    current_user->get_username();
}
BBoard::BBoard(const string &ttl)
    : title(ttl)
{
    user_list.clear();
    message_list.clear();
    current_user = 0;
    current_user->get_username();
}
BBoard::~BBoard()
{
    while(message_list.size() != 0)
    {
        message_list.pop_back();
    }
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
void BBoard::display() const
{
    if(message_list.size() == 0)
    {
        cout << "Nothing to Display." << endl;
        return;
    }
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        if(message_list.at(i)->is_reply())
        {
        }
        else
        {
            cout << "-----------------------------------------------" << endl;
            message_list.at(i)->display();
            cout << "-----------------------------------------------------" << endl;
        }
    }
}
void display2()
{
    cout << "Menu" << endl;
    cout << "\t - Dispaly messages ('D' or 'd')" << endl;
    cout << "\t - Add new message ('N' or 'n')" << endl;
    cout << "\t - Quit ('Q' or 'q')" << endl;
}
const User* BBoard::get_user(const string &name,const string &pw) const
{
    for (unsigned i = 0; i < user_list.size(); i++) 
    {
        if (user_list.at(i).check(name,pw)) 
        {
            return &user_list.at(i);
        }
    }
    return 0;
}
void BBoard::add_user(const string &name, const string &pass)
{
    user_list.push_back(User(name,pass));
}
void BBoard::add_topic() 
{
    string temp_author = current_user->get_username(), temp_subject, temp_body, temp = " ";
    int temp_id = message_list.size() + 1;
    cin.ignore(1000, '\n');
    cout << "Enter Subject: ";
    getline(cin, temp_subject);
    cout << "Enter Body: "; 
    while(temp != "") 
    {
        getline(cin, temp);
        if(temp == "") 
        {
            break;
        }
        temp_body += temp + '\n';
    }
    temp_body = temp_body.substr(0, temp_body.size() - 1);   
    Topic *temp_topic = new Topic(temp_author, temp_subject, temp_body, temp_id);
    message_list.push_back(temp_topic);
    // Topic temp_topic(temp_author, temp_subject, temp_body, temp_id);
    // message_list.push_back(&temp_topic);
}
void BBoard::add_reply() 
{
    string temp_author = current_user->get_username(), temp_subject, temp_body, temp = " ";
    int temp_id = message_list.size() + 1;
    while(temp_id != -1) 
    {
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> temp_id;
        if (temp_id == -1) 
        { 
            return;
        } 
        else if(temp_id == 0 || temp_id > static_cast<int>(message_list.size())) 
        {
            cout << "Invalid Message ID!!" << endl << endl;
        } 
        else 
        {
            break;
        }
    }
    temp_subject = "Re: " + message_list.at(temp_id - 1)->get_subject();
    cout << "Enter Body: ";
    cin.ignore(1000, '\n'); 
    while(temp != "")
    {
        getline(cin, temp);
        if(temp == "") 
        {  
            break;
        }
        temp_body += temp + '\n'; 
    }
    temp_body = temp_body.substr(0, temp_body.size() - 1);
    Reply* temp_reply = new Reply(temp_author, temp_subject, temp_body, temp_id);
    message_list.push_back(temp_reply);
    message_list.at(temp_id - 1)->add_child(temp_reply);
}
//==========================================================
//PUBLIC MEMBER FUNCTIONS
//==========================================================
bool BBoard::load_users(const string &userfile) 
{
    string n, p;
    ifstream fin;
    fin.open(userfile.c_str());
    if(fin.fail()) 
    {
        fin.close();
        return false;
    }
    while (n != "end") 
    {    
        fin >> n; 
        if(n != "end") 
        {  
            fin >> p;
            add_user(n,p); 
        }
    }
    fin.close();
    return true;
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
        for (unsigned i = 0; i < user_list.size();i++)
        {
            if(user_exists(usr,pas,i))
            {
                current_user = &user_list.at(i);
                cout << "Welcome back " << current_user->get_username() << endl;
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
    char choice = 'A'; //input variable
    if (current_user == 0) 
    {
        exit(1);
    }
    while(choice != 'Q' || choice != 'q' ); 
    {
        cout << "Menu" << endl;
        cout << "  " << "- Display Messages ('D' or 'd')" << endl;
        cout << "  " << "- Add New Topic ('N' or 'n')" << endl;
        cout << "  " << "- Add Reply ('R' or 'r')" << endl;
        cout << "  " << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> choice;   
        cout << endl;
        if (choice == 'D' || choice == 'd') 
        { 
            display();
        } 
        else if(choice == 'N' || choice == 'n') 
        { 
            add_topic();
        } 
        else if(choice == 'R' || choice == 'r') 
        {
            add_reply();
        } 
        else if(choice == 'Q' || choice == 'q') 
        { 
            cout << "Bye!" << endl;
            return;
        } 
        else 
        {    
            cout << "Invalid action. Please try again." << endl << endl;
        }
    }    
}
bool BBoard::load_messages(const string &datafile)
{
    ifstream fin;
    fin.open(datafile.c_str());
    if(!fin.is_open())
    {
        return false;
    }
    unsigned messageAmount, temp_id;
    fin >> messageAmount;
    vector< vector<int> > reset_children(messageAmount);
    string temp_author, temp_subject, temp_body, temp_children, new_input, isTopicOrReply;
    for(unsigned i = messageAmount - 1; i != 0; i--)
    {
        fin >> isTopicOrReply;
        temp_id = 0;
        temp_author = temp_subject = temp_body = temp_children = new_input = "";
        while(new_input != "<end>")
        {
            fin >> new_input;
            if (new_input == ":id:") 
            {  
                fin >> temp_id;
            } 
            else if (new_input == ":subject:") 
            {  
                getline(fin, temp_subject);
                temp_subject = temp_subject.substr(1);
            } 
            else if (new_input == ":from:") 
            { 
                fin >> temp_author;
            } 
            else if (new_input == ":children:") 
            { 
                getline(fin, temp_children);
                temp_children = temp_children.substr(1);
                int temp;
                stringstream bin( temp_children );   
                while (bin >> temp) 
                {           
                    reset_children.at(temp_id - 1).push_back(temp);
                }
            }
            else if (new_input == ":body:") 
            { 
                while (new_input != "<end>") 
                {  
                    getline(fin, new_input);
                    if (new_input == "<end>") 
                    {
                        break;
                    }
                    temp_body += new_input + '\n';
                }
                temp_body = temp_body.substr(1);    
                temp_body = temp_body.substr(0, temp_body.size()-1);
            }
        }
        if (isTopicOrReply == "<begin_topic>") 
        {
            message_list.push_back(new Topic(temp_author,temp_subject,temp_body,temp_id));
        } 
        else if(isTopicOrReply == "<begin_reply>") 
        {
            message_list.push_back(new Reply(temp_author,temp_subject,temp_body,temp_id));
        }
    }
    fin.close();//close the input file
    for (unsigned j = 0; j < message_list.size(); j++) 
    {
        for (unsigned k = 0; k < reset_children.at(j).size(); k++) 
        {
            message_list.at(j)->add_child(message_list.at(reset_children.at(j).at(k) - 1));
        }
    }
    return true;
}
bool BBoard::save_messages(const string &datafile)
{
    ofstream fin;
    fin.open(datafile.c_str());
    if(!fin.is_open())
    {
        return false;
    }
    fin << message_list.size() << endl;
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        fin << message_list.at(i)->to_formatted_string();
    }
    fin.close();
    return true;
}