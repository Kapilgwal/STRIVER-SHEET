#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> board)
{
    int n = board.size();
    int m = board[0].size();
    int i = row;
    int j = col;
    // up

    while (i >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }

        i--;
    }

    i = row;
    j = col;

    // diagonal left
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // diagonal right;
    i = row;
    j = col;
    while (i >= 0 and j < m)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j++;
    }

    return true;
}

void solve(int col, vector<vector<char>> &board, vector<vector<vector<char>>> &ans)
{
    if (col == board.size())
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < board.size(); row++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<vector<char>>> nQueen(int n)
{
    vector<vector<char>> board;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] == '.';
        }
    }
    vector<vector<vector<char>>> ans;
    solve(0, board, ans);
    return ans;
}

int main()
{

    int n = 4;
    vector<vector<vector<char>>> ans = nQueen(n);

    for (auto it : ans)
    {
        for (auto ij : it)
        {
            for (auto ik : ij)
            {

                cout << ik << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}