//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 8
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date May 21, 2014
//  ================== END ASSESSMENT HEADER ==============
#include <iostream>
#include "IntList.h"
using namespace std;
int main()
{
    int N = 2;
    IntList tester;
    cout << "Lets start by pushing the front by 2" << endl;
    tester.push_front(2);
    tester.display();
    cout << endl;
    cout << "Now lets continue by multiplying by 2 up to 2^8." << endl;
    tester.push_front(4);
    tester.push_front(8);
    tester.push_front(16);
    tester.push_front(32);
    tester.push_front(64);
    tester.push_front(128);
    tester.push_front(256);
    tester.display();
    cout << endl;
    cout << "Now lets pop everything back to nothing" << endl;
    tester.pop_front();
    tester.pop_front();
    tester.pop_front();
    tester.pop_front();
    tester.pop_front();
    tester.pop_front();
    tester.pop_front();
    tester.pop_front();
    tester.display();
    cout << endl;
    cout << "now lets print 1000 sequential values starting at 2" << endl;
    for(int i = 0; i < 1000; i++)
    {
        tester.push_front(N);
        N = N + 1;
    }
    tester.display();
    cout << endl;
    cout << "Now lets reverse that order" << endl;
    tester.select_sort();
    tester.display();
    cout << endl;
    cout << "and now lets delete them all" << endl;
    for(int i = 0; i < 1000; i++)
    {
        tester.pop_front();
    }
    tester.display();
    cout << endl;
    cout << "Now lets push back a 2 and a 4" << endl;
    tester.push_back(2);
    tester.push_back(4);
    tester.display();
    cout << endl;
    cout << "Now lets push back 10 more values" << endl;
    int k = 0;
    for(int i = 0; i < 10; i++)
    {
        tester.push_back(k);
        cout << " ";
        k++;
    }
    tester.display();
    cout << endl;
    cout << "please select a value you would like to insert: ";
    cin >> N;
    cout << endl;
    tester.insert_sorted(N);
    tester.display();
    cout << endl;
    cout << "Now lets remove any duplicates you have" << endl;
    tester.remove_duplicates();
    tester.display();
    cout << endl;
    return 0;
}