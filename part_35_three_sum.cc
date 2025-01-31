#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> arr)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumBetter(vector<int> arr)
{
    int n = arr.size();
    set<vector<int>> st;
    unordered_map<int, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int sum = -(arr[i] + arr[j]);

            if (mp.find(sum) != mp.end())
            {
                vector<int> temp = {arr[i], arr[j], sum};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumBest(vector<int> arr)
{
    int n = arr.size();

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        // moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
int main()
{

    vector<int> arr = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> ans = threeSumBest(arr);

    for (auto it : ans)
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