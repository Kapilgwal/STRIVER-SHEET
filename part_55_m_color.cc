#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<int>> &adj, const vector<int> &col, int color)
{
    for (auto it : adj[node])
    {
        if (col[it] == color)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &adj, vector<int> &color, int n, int m, int node)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, adj, color, i))
        {
            color[node] = i;
            if (solve(adj, color, n, m, node + 1))
            {
                return true;
            }
            color[node] = -1;
        }
    }
    return false;
}

bool mColor(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n);

    for (auto &it : edges)
    {
        int u = it[0] - 1; 
        int v = it[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, -1);
    return solve(adj, color, n, m, 0);
}

int main()
{
    int n = 4;
    int m = 3;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}};

    bool ans = mColor(edges, n, m);
    cout << (ans ? "1" : "0") << endl;

    return 0;
}
