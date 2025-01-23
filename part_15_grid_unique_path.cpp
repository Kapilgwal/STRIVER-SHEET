#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m)
{
    if (i >= n || j >= m)
    {
        return 0;
    }

    if (i == n - 1 and j == m - 1)
    {
        return 1;
    }

    return solve(i + 1, j, n, m) + solve(i, j + 1, n, m);
}

int uniquePath(int n, int m)
{
    int i = 0;
    int j = 0;
    return solve(i, j, n, m);
}

int main()
{

    int n = 3;
    int m = 7;
    int totalCnt = uniquePath(n, m);
    cout << totalCnt << endl;

    return 0;
}