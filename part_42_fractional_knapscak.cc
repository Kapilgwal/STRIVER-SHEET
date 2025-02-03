#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<pair<int, int>> arr = {{100, 20}, {60, 10}, {120, 30}};
    sort(arr.begin(), arr.end());

    int weight = 50;
    int currWeight = 0;
    double profit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (currWeight + arr[i].second <= weight)
        {
            profit += (double)arr[i].first;
            currWeight += arr[i].second;
        }

        else
        {

            profit += ((double)(arr[i].first) / arr[i].second * ((double)weight - currWeight));
            break;
        }
    }

    cout << profit << endl;

    return 0;
}