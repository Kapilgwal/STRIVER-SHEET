#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int i, int n, vector<int> &temp, int &sum)
{

    if (i >= n)
    {
        temp.push_back(sum);
        return;
    }

    solve(arr, i + 1, n, temp, sum);
    sum += arr[i];
    solve(arr, i + 1, n, temp, sum);
    sum -= arr[i];
}

vector<int> subsetSum(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    vector<int> temp;
    int sum = 0;
    solve(arr, i, n, temp, sum);
    sort(temp.begin(), temp.end());
    return temp;
}

int main()
{
    vector<int> arr = {5, 2, 1};
    vector<int> sum = subsetSum(arr);

    for (auto it : sum)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}