#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr)
{
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotateImage(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> temp;
    for (int i = 0; i < n; i++)
    {
        vector<int> mat;
        for (int j = m - 1; j >= 0; j--)
        {
            mat.push_back(arr[j][i]);
        }

        temp.push_back(mat);
    }

    arr = temp;
}

void rotateImageBetter(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr);
    rotateImageBetter(arr);
    print(arr);
    return 0;
}