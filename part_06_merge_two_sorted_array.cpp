#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

void mergeTwoSortedArray(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = n1 - 1;
    int j = 0;

    while (i >= 0 and j < n2)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
        }
        i--;
        j++;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
int main()
{

    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    print(arr1);
    print(arr2);
    mergeTwoSortedArray(arr1, arr2);
    print(arr1);
    print(arr2);
    return 0;
}