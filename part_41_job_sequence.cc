#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    // vector<vector<int>> job = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<vector<int>> job = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15}};

    vector<vector<int>> jobs;

    for (int i = 0; i < job.size(); i++)
    {
        vector<int> temp = {job[i][1], job[i][2]};
        jobs.push_back(temp);
    }
    set<int> st;
    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < jobs.size(); i++)
    {
        st.insert(jobs[i][0]);
    }

    int profit = 0;
    int j = jobs.size() - 1;
    int cnt = 0;

    while (j >= 0)
    {
        if (st.find(jobs[j][0]) != st.end())
        {
            profit += jobs[j][1];
            st.erase(jobs[j][0]);
            cnt++;
        }
        j--;
    }

    cout << cnt << " " << profit << endl;

    return 0;
}
