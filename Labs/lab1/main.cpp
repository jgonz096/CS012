#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int search(vector<int>& v, int index)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) == index)
        {
            return i;
        }
    }
    return -1;
}
void Remove(vector<int>&v, int index)
{
    swap(v.at(index),v.back());
    v.pop_back();
    if (!v.empty())
    {
        for (int i = index; i < (v.size() - 1); i++)
        {
            swap(v.at(i),v.at(i + 1));
        }
    }
}
int main()
{
    int number = 1, chosenOne, index;
    vector<int>v;
    cout << "Please enter in integers (0 to stop):";
    while (number != 0)
    {
        cin >> number;
        v.push_back(number);
    }
    cout << endl;
    v.pop_back();
    cout << "What number would you like to find and remove?: ";
    cin >> chosenOne;
    cout << endl;
    index = search(v,chosenOne);
    if (index != -1)
    {
        cout << "Found: " << index << endl;
        Remove(v,index);
        cout << "Result: ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " ";
        }
        cout << endl;
    }
    else if (index == -1)
    {
        cout << "Found: " << index << endl;
        cout << "Result: ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " ";
        }
    }
    return 0;
}