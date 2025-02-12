#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> matrix){
    vector<int> temp;

    for(auto i : matrix){
        for(auto j : i){
            temp.push_back(j);
        }
    }

    sort(temp.begin(),temp.end());

    return temp[temp.size()/2];

}

int upperBound(vector<int> arr,int x){
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;

}

int countSmallEqual(vector<vector<int>> matrix,int x){
    int n = matrix.size();
    int m = matrix[0].size();
    int cnt = 0;
    for(int i=0; i<m; i++){
        cnt += upperBound(matrix[i],x);
    }
    return cnt;
}

int findMedianBetter(vector<vector<int>> matrix){
    int low = INT_MAX;
    int high = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<m; i++){
       low = min(low,matrix[i][0]);
       high = max(high,matrix[i][n-1]);
    }

    int req = (n*m)/2;

    while(low <= high){
        int mid = (low + high)/2;

        int smallEqual = countSmallEqual(matrix,mid);
        if(smallEqual <= req){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    return low;
}

int main() {

    vector<vector<int>> matrix = {{1,3,8},{2,3,4},{1,2,5}};
    int median = findMedianBetter(matrix);
    cout<<median<<endl;

return 0;
}