//  =============== BEGIN ASSESSMENT HEADER ================
/// @file ex1s.cpp 
/// @brief assn1/Noide Signals
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 13, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;
double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}
void display(double tmean, double pmean, double tvar, double pvar)
{
    cout << tmean << " " << fixed << setprecision(1) << pmean << " " << tvar << " " << fixed << setprecision(1) << pvar << endl;
}
int main()
{
    srand(time(0));
    double seq1[100], seq2[10000];
    double a = 4.0, b = 10.0;
    double tmean = (a + b) / 2;
    double tvar = ((b - a) * (b - a)) / 12;
    double psum1 = 0;
    double psum2 = 0;
    double pvar1 = 0; //equation is every number in array subtracted by the mean, then squared, devided by 100
    double pvar2 = 0;
    for(int i = 0; i < 100; i++)
    {
        seq1[i] = randFloat(a,b);
        psum1 += seq1[i];
    }
    for(int i = 0; i < 10000; i++)
    {
        seq2[i] = randFloat(a,b);
        psum2 += seq2[i];
    }
    double pmean1 = psum1 / 100;
    double pmean2 = psum2 / 10000;
    for(int i = 0; i < 100; i++)
    {
        pvar1 += pow((pmean1 - seq1[i]),2);
    }
    pvar1 = pvar1 / 100;
    for(int i = 0; i < 10000; i++)
    {
        pvar2 += pow((pmean2 - seq2[i]),2);
    }
    pvar2 = pvar2 / 10000;
    display(tmean,pmean1,tvar,pvar1);
    display(tmean,pmean2,tvar,pvar2);
    return 0;
}