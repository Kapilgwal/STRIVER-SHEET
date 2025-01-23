#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElements(vector<int> arr)
{
    unordered_map<int, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }
    vector<int> ans;
    int n = arr.size();
    for (auto it : mp)
    {
        if (it.second > n / 3)
        {
            ans.push_back(it.first);
        }
    }

    return ans;
}

vector<int> majorityElementsBest(vector<int> arr)
{
    int ele1 = -1;
    int ele2 = -1;
    int cnt1 = 0;
    int cnt2 = 0;
    int n = arr.size();
    vector<int> ans;
    for (auto it : arr)
    {
        if (cnt1 == 0 && ele2 != it)
        {
            cnt1 = 1;
            ele1 = it;
        }

        else if (cnt2 == 0 && ele1 != it)
        {
            cnt2 = 1;
            ele2 = it;
        }

        else if (ele1 == it)
        {
            cnt1++;
        }

        else if (ele2 == it)
        {
            cnt2++;
        }

        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for (auto it : arr)
    {
        if (it == ele1)
        {
            cnt1++;
        }

        if (it == ele2)
        {
            cnt2++;
        }
    }

    if (cnt1 > n / 3)
    {
        ans.push_back(ele1);
    }

    if (cnt2 > n / 3)
    {
        ans.push_back(ele2);
    }

    return ans;
}

int main()
{

    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElementsBest(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}