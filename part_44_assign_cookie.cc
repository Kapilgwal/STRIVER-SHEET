#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = 0;
        int j = 0;
        int n = g.size();
        int m = s.size();
        int count = 0;

        while(i<n and j<m){
            if(g[i] <= s[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return count;
    }
};

int main() {


return 0;
}