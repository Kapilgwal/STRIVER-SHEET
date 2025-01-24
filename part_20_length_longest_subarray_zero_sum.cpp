#include <bits/stdc++.h>
using namespace std;

int longestSubarrayZero(vector<int> arr)
{
    int maxLen = INT_MIN;
    int len = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i + 1; j < arr.size(); j++)
        {
            sum += arr[j];

            if (sum == 0)
            {
                len = j - i;
                maxLen = max(maxLen, len);
            }
        }
    }

    return maxLen;
}

int main()
{

    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int ans = longestSubarrayZero(arr);
    cout << ans << endl;

    return 0;
}