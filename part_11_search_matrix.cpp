#include<bits/stdc++.h>
using namespace std;

int main() {

vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int target = 8;

for(auto i : matrix){
    for(auto j : i){
        if(j == target){
            cout << "Element found"<<endl;
        }
    }
}


return 0;
}