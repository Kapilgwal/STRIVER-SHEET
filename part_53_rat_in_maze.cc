#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &board, vector<vector<int>> &vis, vector<string> &ans, string temp, int i, int j, int n)
{
    // Base case: Reached the destination
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(temp);
        return;
    }

    // Boundary and safety check
    if (i < 0 || j < 0 || i >= n || j >= n || board[i][j] == 0 || vis[i][j] == 1)
    {
        return;
    }

    // Mark cell as visited
    vis[i][j] = 1;

    // Move Down
    solve(board, vis, ans, temp + 'D', i + 1, j, n);

    // Move Left
    solve(board, vis, ans, temp + 'L', i, j - 1, n);

    // Move Right
    solve(board, vis, ans, temp + 'R', i, j + 1, n);

    // Move Up
    solve(board, vis, ans, temp + 'U', i - 1, j, n);

    // Backtrack (unmark cell)
    vis[i][j] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &board, int n)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (board[0][0] == 0 || board[n - 1][n - 1] == 0)
    {
        return {}; // No solution if start or end is blocked
    }

    vector<string> ans;
    solve(board, vis, ans, "", 0, 0, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> board = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> ans = ratInMaze(board, n);

    if (ans.empty())
    {
        cout << "No path found!" << endl;
    }
    else
    {
        for (auto &path : ans)
        {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
