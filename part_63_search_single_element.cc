#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    if (n == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 2] != arr[n - 1])
    {
        return arr[n - 1];
    }

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        else if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) or (mid % 2 == 1  && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleElement(arr);
    cout << ans << endl;

    return 0;
}