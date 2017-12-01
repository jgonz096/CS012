//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp/main.cpp 
/// @brief Assignment/Lab <5> for CS 12 <Spring 2014>
///
/// @author <Jorge Gonzalez> [<jgonz096@ucr.edu>]
/// @date <05/14/2014>
///
/// @par Enrollment Notes 
///     Lecture Section: <001>
/// @par
///     Lab Section: <001>
/// @par
///     TA: <Juan Leon>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include "IntVector.h"
using namespace std;
int main()
{
    IntVector snake(11);
    int index, position, value, size;
    cout << "Size: " << snake.size() << endl;
    cout << "Capacity: " << snake.capacity() << endl;
    if(snake.empty())
    {
        cout << "Yep, snake isn't here." << endl;
    }
    else
    {
        cout << "Snake has arrived." << endl;
    }
    cout << "Input desired index for output: ";
    cin >> index;
    cout << endl;
    cout << snake.at(index) << endl;
    cout << "here is the front: " << snake.front() << endl;
    cout << "here is the back: " << snake.back() << endl;
    cout << "choose a position to insert: ";
    cin >> position;
    cout <<"\nNow choose a value for insertion: ";
    cin >> value;
    snake.insert(position,value);
    for(int i = 0; i < snake.size(); i++)
    {
        cout << snake.at(i) << " ";
    }
    cout << endl;
    cout << "choose a position to erase: ";
    cin >> position;
    snake.erase(position);
    for(int i = 0; i < snake.size(); i++)
    {
        cout << snake.at(i) << " ";
    }
    cout << endl;
    cout << "what would value would you like to add to the end? ";
    cin >> value;
    snake.push_back(value);
    cout << "new size: " << snake.size() << endl;
    cout << "last value: " << snake.back() << endl;
    cout << "mwaahahaha now lets erase that last value and see what happens." << endl;
    snake.pop_back();
    cout << "new size: " << snake.size() << endl;
    cout << "last value: " << snake.back() << endl;
    cout << "now lets erase everything cuz im evil that way >:{D" << endl;
    snake.clear();
    cout << "new size: " << snake.size() << endl;
    cout << "front value: " << snake.front() << endl;
    cout << "last value: " << snake.back() << endl;
    cout << "How big do you want snake to be now? ";
    cin >> size;
    cout << endl;
    snake.resize(size,77);
    cout << "here's your new snake" << endl;
    for(int i = 0; i < snake.size(); i++)
    {
        cout << snake.at(i) << " ";
    }
    cout << endl;
    cout << "now lets change those by assigning new stuff: ";
    cin >> size >> value;
    snake.assign(size,value);
    for(int i = 0; i < snake.size(); i++)
    {
        cout << snake.at(i) << " ";
    }
    cout << endl;
    return 0;
}