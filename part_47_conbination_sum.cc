#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int i, int n, vector<int> &temp, int &target, set<vector<int>> &ans)
{

    if (i >= n)
    {
        return;
    }

    if (target == 0)
    {
        ans.insert(temp);
        return;
    }

    if (target - arr[i] >= 0)
    {
        temp.push_back(arr[i]);
        target -= arr[i];
        solve(arr, i, n, temp, target, ans);
        temp.pop_back();
        target += arr[i];
    }

    solve(arr, i + 1, n, temp, target, ans);
    // sum -= arr[i];
}

vector<vector<int>> combinationSum(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    set<vector<int>> st;
    vector<int> temp;
    int sum = 0;
    int target = 7;
    solve(arr, i, n, temp, target, st);
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> sum = combinationSum(arr);

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