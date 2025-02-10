#include <bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int i, int j, int count)
{
    if (i >= s1.length() || j >= s2.length())
    {
        return count;
    }

    if (s1[i] == s2[j])
    {
        return solve(s1, s2, i + 1, j + 1, count + 1);
    }

    return max(max(solve(s1, s2, i + 1, j, 0), solve(s1, s2, i, j + 1, 0)), count);
}

int longestCommonSubstr(string s1, string s2)
{
    int i = 0;
    int j = 0;

    return solve(s1, s2, i, j, 0);
}

int main()
{

    string s1 = "abcjklp";
    string s2 = "acjkp";

    int ans = longestCommonSubstr(s1, s2);
    cout << ans << endl;

    return 0;
}