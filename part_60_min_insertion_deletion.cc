#include <bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int i, int j)
{
    if (i >= s1.length())
    {
        return s2.length() - j;
    }

    if (j >= s2.length())
    {
        return s1.length() - i;
    }

    if (s1[i] == s2[j])
    {
        return solve(s1, s2, i + 1, j + 1);
    }

    else
    {
        return min(1 + solve(s1, s2, i + 1, j), 1 + solve(s1, s2, i, j + 1));
    }
}

int minInsertionDeletion(string s1, string s2)
{
    int i = 0;
    int j = 0;
    return solve(s1, s2, i, j);
}

int main()
{

    string s1 = "abcd";
    string s2 = "anc";

    int ans = minInsertionDeletion(s1, s2);
    cout << ans << endl;

    return 0;
}