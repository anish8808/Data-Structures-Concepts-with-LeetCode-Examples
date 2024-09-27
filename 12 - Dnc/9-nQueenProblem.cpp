#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> row_visited;
unordered_map<int, bool> upper_visited;
unordered_map<int, bool> down_visited;

bool issafe(int i, int j)
{
    if (row_visited[i] == true)
        return false;

    if (upper_visited[i+j] == true)
        return false;

    if (down_visited[abs(i-j)] == true)
        return false;

    return true;
}

void solve(int n, vector<vector<char>> &board, vector<vector<string>> &ans, int col)
{
    // base condifion
    if (col >= n)
    {

        vector<string> ans1;
        for (int i = 0; i < n; i++)
        {
            string output = "";
            for (int j = 0; j < n; j++)
            {
                output = output + board[i][j];
            }
            ans1.push_back(output);
        }
        ans.push_back(ans1);
        return;
    }

    // 1 case solve karo

    for (int i = 0; i < n; i++)
    {
        int j = col;
        if (issafe(i, j))
        {
            row_visited[i] = true;
            upper_visited[i + j] = true;
            down_visited[i - j] = true;
            board[i][j] = 'Q';
            solve(n, board, ans, col + 1);
            row_visited[i] = false;
            upper_visited[i + j] = false;
            down_visited[i - j] = false;
            board[i][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<vector<char>> borad(n, vector<char>(n, '.'));
    int col = 0;
    solve(n, borad, ans, col);
    return ans;
}

// int main()
// {
//     int n ;
//     cout<<"Enter the number that you want to check for the board ";
//     cin>>n;
//     vector<vector<string>> ans ;

//     ans = solveNQueens(n);

//     for (int i =0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//             cout<<ans[j][i]<<",";

//         cout<<endl;
//     }
//     return 0;
// }

int main()
{
    int n;
    cout << "Enter the number that you want to check for the board: ";
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);

    for (const auto &solution : ans)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}