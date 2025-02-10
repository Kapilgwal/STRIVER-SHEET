#include <bits/stdc++.h>
using namespace std;

string reverse(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }

    return str;
}

int solve(string a, string b, int i, int j)
{
    if (i >= a.length() or j >= b.length())
    {
        return 0;
    }

    if (a[i] == b[j])
    {
        return 1 + solve(a, b, i + 1, j + 1);
    }

    else
    {
        return max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    }
}

int longestPalindromeSubseq(string str)
{
    string str1 = str;
    string str2 = reverse(str);
    int i = 0;
    int j = 0;

    return solve(str1, str2, i, j);
}

int main()
{
    string str = "bbbab";
    int ans = longestPalindromeSubseq(str);

    cout << ans << endl;

    return 0;
}