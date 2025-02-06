#include <bits/stdc++.h>
using namespace std;

int power(int i,int n){
    int ans = 1;
    for(int j=0; j<n; j++){
        ans = ans * i;
    }

    return ans;
}

int nthRoot(int n, int m)
{
    for (int i = 1; i < m; i++)
    {
        if (power(i,n) == m)
        {
            return i;
        }
    }

    return -1;
}

int nthRootBetter(int n, int m)
{
    int low = 1;
    int high = m-1;

    while(low < high){

        int mid = (low + high)/2;

        if (power(mid,n) == m)
        {
            return mid;
        }

        if(power(mid,n) > m){
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    
    }
    return -1;
}

int main()
{

    int n = 4;
    int m = 16;

    int ans = nthRootBetter(n, m);
    cout << ans << endl;

    return 0;
}