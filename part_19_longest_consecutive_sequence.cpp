#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int> arr)
{
    unordered_set<int> st;
    for (auto it : arr)
    {
        st.insert(it);
    }
    int count = 0;
    int maxCount = INT_MIN;
    for (auto it : arr)
    {
        while (st.find(it) != st.end())
        {
            count++;
            it = it + 1;
            maxCount = max(maxCount, count);
        }

        count = 0;
    }

    return maxCount;
}

int main()
{

    vector<int> arr = {3,8,5,7,6};
    int ans = longestConsecutiveSequence(arr);
    cout << ans << endl;

    return 0;
}