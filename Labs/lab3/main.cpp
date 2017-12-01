//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 3
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 18, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
const int Q = 2;
const int R = 3;
const int S = 3;
void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
    int i, j;
    for (i = 0; i < Q; i++)
    {
        for (j = 0; j < S; j++)
        {
            product[i][j] = ((a[i][0] * b[0][j]) + (a[i][0 + 1] * b[0 + 1][j]) + (a[i][0 + 2] * b[0 + 2][j]));
        }
    }
}
void getArr1(int arr[][R])
{
    for (int i = 0; i < Q; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cin >> arr[i][j];
        }
    }
}void getArr2(int arr[][S])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void display(int product[][S])
{
    cout << "Res: " << endl;
    for (int i = 0; i < Q; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr1[Q][R] = {0}, arr2[R][S] = {0}, product[Q][S] = {0};
    cout << "Enter Matrix A(size 2x3): ";
    getArr1(arr1);
    cout << endl;
    cout << "Enter Matrix B(size 3x3): ";
    getArr2(arr2);
    cout << endl;
    matrixMult(arr1,arr2,product);
    display(product);
    cout << endl;
    return 0;
}