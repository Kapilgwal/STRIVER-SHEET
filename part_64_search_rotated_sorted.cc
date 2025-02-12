#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int k)
{

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }

        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {

                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        else
        {
            if (arr[mid] <= k and k <= arr[high])
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2,3};
    int k = 3;
    int ans = search(arr, k);
    cout << ans << endl;
    return 0;
}