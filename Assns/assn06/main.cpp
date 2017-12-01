//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/main.cpp 
/// @brief Assignment/Lab 8 for CS 12 Fall, 2014
///
/// @author Jorge Gonzalez [jgonz096@gmail.com]
/// @date 11/22/14
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Ali Mohammadkhan
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include "IntList.h"
using namespace std;
void test_select_sort(IntList list)
{
    list.select_sort();
}
void test_push_front(IntList list)
{
    list.display();
    cout << endl;
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    list.push_front(9);
    cout << "current list: ";
    list.display();
    cout << endl;
    list.display();
    cout << endl;
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    cout << "current list: ";
    list.display();
}
void test_push_back(IntList list)
{
    list.display();
    cout << endl;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    cout << "current list: ";
    list.display();
    cout << endl;
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    cout << "current list: ";
    list.display();
}
void test_insert_sorted(IntList list)
{
    cout << "current list: ";
    list.display();
    cout << endl;
    list.insert_sorted(5);
    list.insert_sorted(4);
    list.insert_sorted(15);
    list.insert_sorted(1);
    list.insert_sorted(8);
    list.insert_sorted(5);
    list.insert_sorted(4);
    list.insert_sorted(15);
    list.insert_sorted(1);
    list.insert_sorted(8);
    cout << "current list: ";
    list.display();
    cout << endl;
    list.display();
    cout << endl;
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    cout << "current list: ";
    list.display();
}
void test_remove_duplicates(IntList list)
{
    list.push_back(563);
    list.push_back(563);
    list.push_back(359);
    list.push_back(563);
    list.push_back(359);
    list.push_back(191);
    list.push_back(185);
    list.display();
    list.remove_duplicates();
    cout << endl;
    list.display();
}
int main()
{
    IntList list;
    cout << "Push_front test: " << endl;
    test_push_front(list);
    cout << endl;
    cout << "Push_back test: " << endl;
    test_push_back(list);
    cout << endl;
    cout << "Insert_sorted test: " << endl;
    test_insert_sorted(list);
    cout << endl;
    cout << "Remove_duplicates test: " << endl;
    test_remove_duplicates(list);
    cout << endl;
    return 0;
}