#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{

    cout << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

void sort_0_1_2(vector<int> &arr)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for (auto it : arr)
    {
        if (it == 0)
            zero++;
        else if (it == 1)
            one++;
        else if (it == 2)
            two++;
    }
    int i = 0;
    while (zero)
    {
        arr[i++] = 0;
        zero--;
    }

    while (one)
    {
        arr[i++] = 1;
        one--;
    }

    while (two)
    {
        arr[i++] = 2;
        two--;
    }
}

void sort_0_1_2_better(vector<int> &arr)
{
    int mid = 0;
    int high = arr.size() - 1;

    for (int low = 0; low < high; low++)
    {
        if (arr[low] == 0)
        {
            continue;
        }

        if (arr[mid] == 1)
        {
            swap(arr[low], arr[mid]);
            mid++;
        }

        if (arr[mid] == 2)
        {
            swap(arr[low], arr[mid]);
            low--;
        }
    }
}

void sort_0_1_2_better_2(vector<int> &arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1)
        {
            mid++;
        }

        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{

    vector<int> arr = {0, 2, 1, 0, 0, 1, 0, 1, 2, 0};
    print(arr);
    sort_0_1_2_better_2(arr);
    print(arr);
    return 0;
}