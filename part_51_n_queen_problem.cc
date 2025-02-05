#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, const vector<vector<char>> &board)
{
    int n = board.size();

    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check the right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(int row, vector<vector<char>> &board, vector<vector<vector<char>>> &ans)
{
    int n = board.size();

    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q'; // Place Queen
            solve(row + 1, board, ans);
            board[row][col] = '.'; // Backtrack
        }
    }
}

vector<vector<vector<char>>> nQueen(int n)
{
    vector<vector<char>> board(n, vector<char>(n, '.')); // Correct board initialization
    vector<vector<vector<char>>> ans;
    solve(0, board, ans);
    return ans;
}

int main()
{
    int n = 8;
    vector<vector<vector<char>>> ans = nQueen(n);

    for (auto &it : ans)
    {
        for (auto &ij : it)
        {
            for (auto &ik : ij)
            {
                cout << ik << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout<<ans.size()<<endl;

    return 0;
}
