//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 3
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 18, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
const int M = 2;
const int N = 3;
void matrixAdd(const int a[][N], const int b[][N], int sum[][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}
void getArr(int arr[][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void display(int sum[][N])
{
    cout << "Res: " << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr1[M][N], arr2[M][N], sum[M][N];
    cout << "Enter Matrix A: ";
    getArr(arr1);
    cout << endl;
    cout << "Enter Matrix B: ";
    getArr(arr2);
    cout << endl;
    matrixAdd(arr1,arr2,sum);
    display(sum);
    cout << endl;
    return 0;
}