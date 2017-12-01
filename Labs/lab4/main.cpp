//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 4
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 27, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
class Rational
{
     private:
        int numer;
        int denom; 
     public:
        Rational();
        Rational(int); 
        Rational(int, int); 
        const Rational add(const Rational &) const; 
        const Rational subtract(const Rational &) const; 
        const Rational multiply(const Rational &) const; 
        const Rational divide(const Rational &) const; 
        void display() const; 
};
Rational::Rational()
    : numer(0), denom(1)
{
}
Rational::Rational(int a)
    : numer(a), denom(1)
{
}
Rational::Rational(int a, int b)
    : numer(a), denom(b)
{
}
const Rational Rational::add(const Rational& a) const
{
    int newNumer = (numer * a.denom) + (denom * a.numer);
    int newDenom = (denom * a.denom);
    Rational c(newNumer,newDenom);
    return c;
}
const Rational Rational::subtract(const Rational& a) const
{
    int newNumer = (numer * a.denom) - (denom * a.numer);
    int newDenom = (denom * a.denom);
    Rational c(newNumer,newDenom);
    return c;
}
const Rational Rational::multiply(const Rational& a) const
{
    int newNumer = (numer * a.numer);
    int newDenom = (denom * a.denom);
    Rational c(newNumer,newDenom);
    return c;
}
const Rational Rational::divide(const Rational& a) const
{
    int newNumer = (numer *a.denom);
    int newDenom = (denom * a.numer);
    Rational c(newNumer,newDenom);
    return c;
}
void Rational::display() const
{
    cout << numer << "/" << denom;
}

int main()
{
    Rational test1, test2(5), test3(5,4), Empty;
    test1.display();
    cout << endl;
    test2.display();
    cout << endl;
    test3.display();
    cout << endl;
    Empty = test3.add(test2);
    Empty.display();
    cout << endl;
    Empty = test3.subtract(test2);
    Empty.display();
    cout << endl;
    Empty = test3.multiply(test2);
    Empty.display();
    cout << endl;
    Empty = test3.divide(test2);
    Empty.display();
    cout << endl;
    return 0;
}