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
void rand_mv(double mean, double var)
{
    double a, b;
    a = mean - sqrt(3 * var);
    b = mean + sqrt(3 * var);
    cout << "a: " << a << " b: " << b << endl;
}
int main()
{
    srand(time(0));
    double mean, var;
    cout << "Enter Mean ";
    cin >> mean;
    cout << endl;
    cout << "Enter Variance ";
    cin >> var;
    rand_mv(mean,var);
    return 0;
}