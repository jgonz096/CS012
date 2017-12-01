//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief assn2/Temperature Distribution
///
/// @author Jorge Gonzalez [jgonz096@ucr.edu]
/// @date October 19, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void getFiles(string& ifile, string& ofile)
{
    cout << "Please enter input file: ";
    cin >> ifile;
    cout << endl;
    cout << "Please enter output file: ";
    cin >> ofile;
    cout << endl;
}
void getSides(double grid[][8], double up, double right, double down, double left)
{
    for (int i = 0; i < 8; i++)
    {
        grid[0][i] = up;
    }
    for (int i = 1; i < 6; i++)
    {
        grid[i][0] = left;
        grid[i][7] = right;
    }
    for (int i = 0; i < 8; i++)
    {
        grid[5][i] = down;
    }
}
void equalize(double grid[][8], double oldGrid[][8], double& difference)
{
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            oldGrid[i][j] = grid[i][j];
            grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4;
            if (fabs(grid[i][j] - oldGrid[i][j]) > difference)
            {
                difference = fabs(grid[i][j] - oldGrid[i][j]);
            }
        }
    }
}
int main()
{
    double grid[6][8] = {0}, oldGrid[6][8] = {0}, up, right, down, left, tol = 0, dif = 0;
    string ifile, ofile;
    ifstream file1;
    ofstream file2;
    getFiles(ifile,ofile);
    file1.open(ifile.c_str());
    file2.open(ofile.c_str());
    if (!file1.is_open())
    {
        cout << "Input file does not exist" << endl;
        return 1;
    }
    if (!file2.is_open())
    {
        cout << "Output file does not exist" << endl;
        return 1;
    }
    file1 >> up >> right >> down >> left >> tol;
    getSides(grid,up,right,down,left);
    if (tol != 0)
    {
        equalize(grid,oldGrid,dif);
    }
    while (dif > tol)
    {
        dif = 0;
        equalize(grid, oldGrid, dif);
    }
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            file2 << grid[i][j] << " ";
        }
        file2 << endl;
    }
    file1.close();
    file2.close();
    return 0;
}