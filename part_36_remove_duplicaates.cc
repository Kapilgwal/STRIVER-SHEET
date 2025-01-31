#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &temp, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (temp[i] != temp[j])
        {
            i++;
            temp[i] = temp[j];
        }
    }

    return i + 1;
}

int main()
{

    vector<int> temp = {1, 1, 2, 2, 2, 3, 3};
    int n = temp.size();
    int k = removeDuplicates(temp, n);

    for (int i = 0; i < k; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}