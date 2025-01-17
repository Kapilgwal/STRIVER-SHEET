#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> temp1(n1);
    vector<int> temp2(n2);

    for (int i = 0; i < n1; i++)
        temp1[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        temp2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low, count = 0;

    while (i < n1 && j < n2)
    {
        if (temp1[i] <= temp2[j])
        {
            arr[k++] = temp1[i++];
        }
        else
        {
            arr[k++] = temp2[j++];
            count += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = temp1[i++];
    while (j < n2)
        arr[k++] = temp2[j++];

    return count;
}

int count(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    int ans = 0;

    ans += count(arr, low, mid);
    ans += count(arr, mid + 1, high);
    ans += solve(arr, low, mid, high);

    return ans;
}

int countInversionBest(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    return count(arr, low, high);
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int ans = countInversionBest(arr);
    cout << "Number of inversions: " << ans << endl;
    return 0;
}
