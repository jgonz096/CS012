//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Date.cpp 
/// @brief assn3/Date Class
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 27, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
#ifndef DATE_H
#define DATE_H
class Date
{
    private:
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
        bool isLeap(unsigned) const;
        unsigned daysPerMonth(unsigned m, unsigned y);
        string name(unsigned m) const;
        unsigned number(const string& mn) const;
    public:
        Date();
        Date(unsigned d, unsigned m, unsigned y);
        Date(const string& mn, unsigned d, unsigned y);
        void printNumeric() const;
        void printAlpha() const;
};
#endif