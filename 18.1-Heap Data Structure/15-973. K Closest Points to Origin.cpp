// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<double, vector<int>>> pq;
    for (auto j : points)
    {
        int x = j[0];
        int y = j[1];
        double distance = sqrt(x * x + y * y);
        pq.push({distance, j});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<vector<int>> ans;
    while (!pq.empty())
    {
        auto ele = pq.top();
        ans.push_back(ele.second);
        pq.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> ans = kClosest(grid, 3);
    return 0;
}