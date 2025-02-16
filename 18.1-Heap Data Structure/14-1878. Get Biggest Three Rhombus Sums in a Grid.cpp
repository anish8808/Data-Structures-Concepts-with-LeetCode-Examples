// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    priority_queue<int> pq;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = grid[i][j];
            pq.push(sum);

            int l = j - 1;
            int r = j + 1;
            int u = i - 1;
            int d = i + 1;
            while (l >= 0 && r < n && u >= 0 && d < m)
            {
                sum = grid[i][l] + grid[i][r] + grid[u][j] + grid[d][j];
                int col1 = j - 1;
                int col2 = j + 1;
                for (int row1 = u + 1, row2 = d - 1; row1 < i && row2 > i; row1++, row2--)
                {
                    sum += grid[row1][col1] + grid[row1][col2] + grid[row2][col1] + grid[row2][col2];
                    col1--;
                    col2++;
                }
                pq.push(sum);

                l--;
                r++;
                u--;
                d++;
            }
        }
    }
    vector<int> ans;
    while (ans.size() != 3 && !pq.empty())
    {
        if (ans.size() == 0 || ans.back() != pq.top())
            ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = getBiggestThree(grid);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}