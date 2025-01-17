#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans = {1, 3, 4, 2, 2};
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] == ans[i + 1])
        {
            cout << ans[i] << endl;
            break;
        }
    }

    return 0;
}