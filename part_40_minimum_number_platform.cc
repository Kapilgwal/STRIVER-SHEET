#include<bits/stdc++.h>
using namespace std;

int main() {

vector<int> arvl = {900,945,955,1100,1500,1800};
vector<int> dept = {920,1200,1130,1150,1900,2000};

sort(arvl.begin(),arvl.end());
sort(dept.begin(),dept.end());

int cnt = 1;
int ans = 1;
int i = 1;
int j = 0;
int n = arvl.size();

while(i<n and j< n){
    if(arvl[i] <= dept[j]){
        cnt++;
        i++;
    }

    else{
        cnt--;
        j++;
    }

    ans = max(ans,cnt);


}
cout<<ans;

return 0;
}