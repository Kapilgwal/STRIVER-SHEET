#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> temp = {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1};

    int cnt = 0;
    int maxCnt = 0;

    for (auto it : temp)
    {
        if (it)
        {
            cnt++;
        }

        else
        {
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
    }

    maxCnt = max(maxCnt, cnt);
    cout << maxCnt << endl;
    return 0;
}