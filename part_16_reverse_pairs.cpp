#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2LL * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }

    return cnt;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int solve(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += solve(arr, low, mid);
    cnt += solve(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);
    return cnt;
}

int reversePairBetter(vector<int> arr)
{
    return solve(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {3, 2, 1, 4};
    int ans = reversePairBetter(arr);
    cout << ans << endl;
    return 0;
}
