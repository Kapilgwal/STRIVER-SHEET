#include <bits/stdc++.h>
using namespace std;

int countXorr(vector<int> arr, int k)
{
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int xorr = 0;
        for (int j = i; j < arr.size(); j++)
        {
            xorr = xorr ^ arr[j];

            if (xorr == k)
            {
                count += 1;
            }
        }
    }

    return count;
}

int countXorrBetter(vector<int> arr, int k)
{
    int count = 0;
    int xorr = 0;

    int j = 0;
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[xorr]++;
    while (j < n)
    {
        xorr = xorr ^ arr[j];

        int rem = k ^ xorr;

        count += mp[rem];

        mp[xorr]++;
        j++;
    }

    return count;
}

int main()
{

    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = countXorr(arr, k);
    cout << ans << endl;

    return 0;
}