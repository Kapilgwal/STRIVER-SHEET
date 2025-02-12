#include<bits/stdc++.h>
using namespace std;

bool comp(string &a,string &b){
    return (a+b) > (b+a);
}

string solve(vector<string> arr){
    sort(arr.begin(),arr.end(),comp);

    string ans = "";

    for(auto it : arr){
        ans += it;
    }

    return ans;
}

int main() {

vector<string> arr = {"3","20","9","1"};
string ans = solve(arr);
cout<<ans<<endl;

return 0;
}