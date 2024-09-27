#include <bits/stdc++.h>

using namespace std;


bool isfare(int src_x, int src_y, vector<vector<bool>> &visited, int n, vector<vector<int>> &m)
{
    if (src_x < 0 || src_y < 0 || src_x >= n || src_y >= n )
        return false;
    
    if(visited[src_x][src_y]== true)
        return false;

    if(m[src_x][src_y]==0)
        return 0;

    return true;
}
void solve(vector<vector<int>> &m, int n, vector<vector<bool>> &visited, vector<string> &ans, string output, int src_x, int src_y)
{
    if (src_x == n - 1 && src_y == n - 1)
    {
        ans.push_back(output);
        return;
    }

    // up(x-1 , y) // down(x+1 , y) // left(x , y-1) //right (x , y+1)

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char move[] = {'U', 'D', 'L', 'R'};

    for (int i = 0; i < 4; i++)
    {
        int new_x = src_x + dx[i];
        int new_y = src_y + dy[i];
        if (isfare(new_x, new_y, visited, n, m))
        {
            visited[new_x][new_y] = true;
            output.push_back(move[i]);
            solve(m, n, visited, ans, output, new_x, new_y);
            visited[new_x][new_y] = false;
            output.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    string output = "";
    if (m[0][0] == 0)
        return ans;

    int src_x = 0;
    int src_y = 0;

    visited[0][0] = true;
    solve(m, n, visited, ans, output, src_x, src_y);

    return ans;
}

int main()
{
    vector<vector<int>> m = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}};
    vector<string> ans;
    ans = findPath(m, 3);

    for (auto &val : ans)
    {
        cout << val << " ";
    }
    return 0;
}