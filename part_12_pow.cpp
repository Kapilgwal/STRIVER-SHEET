#include <bits/stdc++.h>
using namespace std;

double getPow(float a, int n)
{
    double res = 1.0;
    for (int i = 0; i < n; i++)
    {
        res *= a;
    }

    return (double)res;
}

double getPowBetter(float a, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0)
    {
        nn = -1 * nn;
    }

    while (nn)
    {
        if (nn % 2)
        {
            ans *= a;
            nn -= 1;
        }

        else
        {
            a *= a;
            nn = nn / 2;
        }
    }

    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }

    return ans;
}

int main()
{

    float a = 2.10000;
    int n = 3;
    double ans = getPowBetter(a, n);
    cout << ans << endl;

    return 0;
}