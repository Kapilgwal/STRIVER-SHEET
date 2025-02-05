#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr,int i,vector<int> temp,set<vector<int>> &ans){
    if(i >= arr.size()){
        ans.insert(arr);
        return;
    }

    solve(arr,i+1,temp,ans);

    for(int j=0; j<arr.size(); j++){
        swap(arr[i],arr[j]);
        solve(arr,i+1,temp,ans);
        swap(arr[i],arr[j]);
    }
}

vector<vector<int>> allPermutation(vector<int> arr){
    int i = 0;
    set<vector<int>> st;
    vector<int> temp;
    solve(arr,i,temp,st);
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main() {

vector<int> arr = {1,2,3};
vector<vector<int>> ans = allPermutation(arr);
for(auto i : ans){
    cout<<"[";
    for(auto j : i){
        cout<<j<<" ";
    }
    cout<<"]\n";
}

return 0;
}