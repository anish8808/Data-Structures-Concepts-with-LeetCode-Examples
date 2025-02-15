// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    unordered_set<int> set;
    int m = grid.size();
    int n = grid[0].size();

    int i = m / 2;
    int j = n / 2;
    int k = min(i, min(m - 1 - i, min(j, n - 1 - j)));

    int count = 0;
    while (count <= k)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int top = grid[i - k][j];
                int down = grid[i + k][j];
                int left = grid[i][j - k];
                int right = grid[i][j + k];

                set.insert(top + down + left + right);
            }

        count++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : set)
    {
        pq.push(i);
        while (pq.size() > 3)
        {
            pq.top();
        }
    }

    vector<int> ans;
    while (!pq.empty())
    {
        int ele = pq.top();
        ans.push_back(ele);
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