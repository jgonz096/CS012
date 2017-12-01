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
void fillArray(double arr[], double a, double b)
{
    for(int i = 0; i < 500; i++)
    {
        arr[i] = randFloat(a,b);
    }
}
double findMean(double arr[])
{
    double sum = 0;
    for(int i = 0; i < 500; i++)
    {
        sum += arr[i];
    }
    return (sum / 500);
}
double findVar(double arr[], double a, double b, double pMean)
{
    double sum = 0;
    for(int i = 0; i < 500; i++)
    {
        sum += (pow(pMean - arr[i],2));
    }
    return sum / 500;
}
void display(double tmean, double pmean, double tvar, double pvar)
{
    cout << tmean << " " << fixed << setprecision(1) << pmean << " " << tvar << " " << fixed << setprecision(1) << pvar << endl;
}
int main()
{
    srand(time(0));
    double seq1[500], seq2[500];
    double a = (8 - sqrt(6)) / 2;
    double b = (8 + sqrt(6)) / 2;
    double c = (8 - sqrt(24)) / 2;
    double d = (8 + sqrt(24)) / 2;
    fillArray(seq1,a,b);
    fillArray(seq2,c,d);
    double tMean = 4;
    double tVar1 = .5;
    double tVar2 = 2;
    double pMean1 = findMean(seq1);
    double pMean2 = findMean(seq2);
    double pVar1 = findVar(seq1,a,b,pMean1);
    double pVar2 = findVar(seq2,c,d,pMean2);
    display(tMean,pMean1,tVar1,pVar1);
    display(tMean,pMean2,tVar2,pVar2);
    return 0;
}