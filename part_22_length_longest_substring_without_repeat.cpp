#include <bits/stdc++.h>
using namespace std;

int longestLength(string s)
{
    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        unordered_set<char> st;
        int len = 0;
        for (int j = i; j < s.length(); j++)
        {
            char ch = s[j];

            if (st.find(ch) == st.end())
            {
                len = j - i + 1;
                ans = max(ans, len);
                st.insert(ch);
            }

            else
            {
                len = 0;
            }
        }
    }

    return ans;
}

int longestLengthBetter(string s)
{
    unordered_set<char> st;
    int i = 0;
    int len = 0;
    int maxLen = 0;

    for (int j = 0; j < s.length(); j++)
    {
        char ch = s[j];

        if (st.find(ch) != st.end())
        {
            while (i < j && st.find(ch) != st.end())
            {
                st.erase(s[i]);
                i++;
            }
        }
        st.insert(ch);
        len = j - i + 1;
        maxLen = max(maxLen, len);
    }

    return maxLen;
}
int main()
{

    string s = "abcdbb";
    cout << longestLengthBetter(s) << endl;

    return 0;
}