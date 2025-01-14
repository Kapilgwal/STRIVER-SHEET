#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> prices = {7, 6, 4, 3, 1};
    int n = prices.size();
    int maxProfit = -1;
    int minPrice = prices[0];

    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    cout << maxProfit << endl;

    return 0;
}