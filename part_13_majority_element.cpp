#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }

        if (count > n / 2)
        {
            return nums[i];
        }
    }

    return -1;
}

int majorityElementBetter(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }

    return -1;
}

int majorityElementBest(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    int ele;
    for (int i = 0; i < n; i++)
    {

        if (count == 0)
        {
            count = 1;
            ele = nums[i];
        }
        else if (ele == nums[i])
        {
            count++;
        }
        else{
            count--;

        }
        
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele)
        {
            count++;
        }
    }

    if (count > n / 2)
    {
        return ele;
    }

    else
    {
        return -1;
    }
}

int main()
{

    vector<int> nums = {3, 2, 3};
    int ans1 = majorityElementBest(nums);
    cout << ans1 << endl;

    return 0;
}