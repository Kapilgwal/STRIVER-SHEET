#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int i, int n, vector<int> &temp, set<vector<int>> &ans)
{

    if (i >= n)
    {
        ans.insert(temp);
        return;
    }

    solve(arr, i + 1, n, temp, ans);
    // sum += arr[i];
    temp.push_back(arr[i]);
    solve(arr, i + 1, n, temp, ans);
    // sum -= arr[i];
    temp.pop_back();
}

vector<vector<int>> subsetSum(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    set<vector<int>> st;
    vector<int> temp;
    int sum = 0;
    solve(arr, i, n, temp, st);
    vector<vector<int>> ans(st.begin(), st.end());
    // sort(temp.begin(), temp.end());
    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 1};
    vector<vector<int>> sum = subsetSum(arr);

    for (auto it : sum)
    {
        for (auto j : it)
        {

            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}