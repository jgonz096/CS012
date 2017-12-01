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
#include "Date.h"
using namespace std;
//==============================================================================
//Constructors
//==============================================================================
Date::Date()
    : day(1), month(1), year(2000)
{
    monthName = "January";
}
Date::Date(unsigned m, unsigned d, unsigned y)
    : month(m), day(d), year(y)
{
    if (month == 0)
    {
        month = 1;
        monthName = "January";
    }
    if (month > 12)
    {
        month = 12;
        monthName = "December";
    }
    if(month == 2)
    {
        monthName = "February";
        if(day > daysPerMonth(month,year))
        {
            day = daysPerMonth(month,year);
            cout << "Invalid date values: Date corrected to ";
            printNumeric();
            cout << "." << endl; 
        }
    }
    monthName = name(month);
    if (day > daysPerMonth(month,year))
    {
        day = daysPerMonth(month,year);
        cout << "Invalid date values: Date corrected to ";
        printNumeric();
        cout << "." << endl;
    }
}
Date::Date(const string& mn, unsigned d, unsigned y)
    : monthName(mn), day(d), year(y)
{
    if( ( monthName != "January" && monthName != "january" ) &&
    ( monthName != "February" && monthName != "february" ) &&
    ( monthName != "March" && monthName != "march" ) &&
    ( monthName != "April" && monthName != "april" ) &&
    ( monthName != "May" && monthName != "may" ) &&
    ( monthName != "June" && monthName != "june" ) && 
    ( monthName != "July" && monthName != "july" ) && 
    ( monthName != "August" && monthName != "august" ) && 
    ( monthName != "September" && monthName != "September" ) && 
    ( monthName != "October" && monthName != "october" ) && 
    ( monthName != "November" && monthName != "november" ) && 
    ( monthName != "December" && monthName != "december" ) )
    {
        cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
        monthName = "January";
        day = 1;
        year = 2000;
        month = 1;
    }
    else
    {
        month = number(monthName);
        if(day > daysPerMonth(month,year))
        {
            day = daysPerMonth(month,year);
        }
    }
}
//==============================================================================
//Public Member Functions
//==============================================================================
void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const
{
    cout << monthName << " " << day << ", " << year;
}
//==============================================================================
//==============================================================================
//Private Member Functions
//==============================================================================
bool Date::isLeap(unsigned year) const
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}
unsigned Date::daysPerMonth(unsigned m, unsigned y)
{
    if((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (month == 10) || (m == 12))
    {
        return 31;
    }
    else if((m == 4) || (m == 6) || (m == 9) || (m == 11))
    {
        return 30;
    }
    else if (m == 2)
    {
        if (isLeap(y))
        {
           return 29;
        }
        else
        return 28;
    }
}
string Date::name(unsigned m) const
{
    if( month == 1)
    {
        return "January";
    }
    else if( month == 2)
    {
        return "February";
    }
    else if( month == 3)
    {
        return "March";
    }
    else if( month == 4)
    {
        return "April";
    }
    else if( month == 5)
    {
        return "May";
    }
    else if( month == 6)
    {
        return "June";
    }
    else if( month == 7)
    {
        return "July";
    }
    else if( month == 8)
    {
        return "August";
    }
    else if( month == 9)
    {
        return "September";
    }
    else if( month == 10)
    {
        return "October";
    }
    else if( month == 11)
    {
        return "November";
    }
    else if( month == 12)
    {
        return "December";
    }
}
unsigned Date::number(const string& mn) const
{
    if((mn == "January") || (mn == "january"))
    {
        return 1;
    }
    else if((mn == "February") || (mn == "february"))
    {
        return 2;
    }
    else if((mn == "March") || (mn == "march"))
    {
        return 3;
    }
    else if((mn == "April") || (mn == "april"))
    {
        return 4;
    }
    else if((mn == "May") || (mn == "may"))
    {
        return 5;
    }
    else if((mn == "June") || (mn == "june"))
    {
        return 6;
    }
    else if((mn == "July") || (mn == "july"))
    {
        return 7;
    }
    else if((mn == "August") || (mn == "august"))
    {
        return 8;
    }
    else if((mn == "September") || (mn == "september"))
    {
        return 9;
    }
    else if((mn == "October") || (mn == "october"))
    {
        return 10;
    }
    else if((mn == "November") || (mn == "november"))
    {
        return 11;
    }
    else if((mn == "December") || (mn == "december"))
    {
        return 12;
    }
}