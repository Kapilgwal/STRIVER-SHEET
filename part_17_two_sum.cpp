#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> arr, int target)
{

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

bool twoSumBetter(vector<int> arr, int target)
{
    unordered_map<int, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }

    for (auto it : arr)
    {
        int diff = target - it;
        if (mp.find(diff) != mp.end())
        {
            return true;
        }
    }

    return false;
}

bool twoSumBest(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int sum = arr[low] + arr[high];

        if (sum == target)
        {
            return true;
        }

        else if (sum > target)
        {
            high--;
        }

        else
        {
            low++;
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 15;
    int ans1 = twoSumBest(arr, target);
    cout << ans1 << endl;

    return 0;
}