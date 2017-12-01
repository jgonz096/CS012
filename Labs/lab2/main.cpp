//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 2
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 15, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
void mystrcat(char destination[], const char source[])
{
    int a = 0, b = 0;
    while(destination[a] != '\0')
    {
        a++;
    }
    while (source[b] != '\0')
    {
        destination[a] = source[b];
        a++;
        b++;
    }
    destination[a] = source[b];
}
void display(char string[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        cout << string[i];
        i++;
    }
    cout << endl;
}
int main()
{
    char stringOne[1000] = "As I walk through the valley of the shadow of death, ";
    char stringTwo[] = "I shall fear no evil.";
    mystrcat(stringOne,stringTwo);
    display(stringOne);
    return 0;
}