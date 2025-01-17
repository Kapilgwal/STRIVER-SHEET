#include <bits/stdc++.h>
using namespace std;

pair<int, int> missing_repeating(vector<int> arr)
{
    int n = arr.size();
    int missing, repeating;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (auto it : arr)
        {
            if (it == i)
            {
                count++;
            }
        }

        if (count == 0)
        {
            missing = i;
        }

        if (count == 2)
        {
            repeating = i;
        }
    }

    return {missing, repeating};
}

pair<int, int> missing_repeating_better(vector<int> arr)
{
    int n = arr.size();
    int missing, repeating;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            missing = i;
        }

        if (mp[i] == 2)
        {
            repeating = i;
        }
    }

    return {missing, repeating};
}

int main()
{

    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    pair<int, int> ans = missing_repeating(arr);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}