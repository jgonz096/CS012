//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<5>/main.cpp
/// @brief Assignment/Lab <7> for CS 12 <Spring 2014>
///
/// @author <Jorge Gonzalez> [jgonz096@ucr.edu]
/// @date <28 May 2104>
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
//  ================== END ASSESSMENT HEADER
// ________/)______./¯"""/')
// ¯¯¯¯¯¯¯¯¯\)¯¯¯¯¯'\_„„„„\)
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
bool diophantine(int a, int b, int c, int &x, int &y)
{
    if((c % (__gcd(a,b))) != 0)
    {
        return false;
    }
    if((a % b) == 0)
    {
        x = 0;
        y = (c / b);
    }
    else
    {
        int q = (a / b);
        int r = (a % b);
        int u;
        int v;
        diophantine(b,r,c,u,v);
        x = v;
        y = u - q * x;
    }
    return true;
}
int main()
{
    string inputFile, outputFile;
    int a, b, c, x, y;
    cout << "Which input file would you like to use today sir?" << endl;
    cin >> inputFile;
    cout << "\nNow which output file would you like to use today sir?" << endl;
    cin >> outputFile;
    ifstream inFile;
    ofstream outFile;
    inFile.open(inputFile.c_str());
    outFile.open(outputFile.c_str());
    while(inFile >> a >> b >> c)
    {
        if(diophantine(a,b,c,x,y))
        {
            outFile << x << " " << y << endl;
        }
        else
        {
            outFile << "No solution!" << endl;
        }
    }
    return 0;
}