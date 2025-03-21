#include <bits/stdc++.h>

using namespace std;

int solve(int capacity, vector<int> &val, vector<int> &wt, int index)
{
    // basecase
    if (index == 0)
    {
        if (capacity >= wt[index])
        {
            return val[index];
        }
        else
        {
            return 0;
        }
    }

    int inc = 0;
    if (capacity >= wt[index])
    {
        inc = val[index] + solve(capacity - wt[index], val, wt, index - 1);
    }
    int exec = 0 + solve(capacity, val, wt, index - 1);

    int final = max(inc, exec);

    return final;
}

// solve using memoisation DP
int solveUsingMem(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int>> &dp)
{
    // basecase
    if (index == 0)
    {
        if (capacity >= wt[index])
        {
            return val[index];
        }
        else
        {
            return 0;
        }
    }

    if (dp[capacity][index] != -1)
        return dp[capacity][index];

    int inc = 0;
    if (capacity >= wt[index])
    {
        inc = val[index] + solveUsingMem(val, wt, capacity - wt[index], index - 1, dp);
    }
    int exec = 0 + solveUsingMem(val, wt, capacity, index - 1, dp);

    dp[capacity][index] = max(inc, exec);

    return dp[capacity][index];
}

// solve using tab method

int solveUsingTab(int capacity, vector<int> &val, vector<int> &wt, int index)
{
    // 1st- step create dp array
    vector<vector<int>> dp(capacity + 1, vector<int>(index + 2, 0));

    // 2nd step initalised the dp array by analysing the base case
    for (int w = wt[0]; w <= capacity; w++)
    {
        dp[w][0] = val[0];
    }

    // 3rd step reverse the paramteres of memoisation technique and copy paste logic
    // capaciy [W to 0]
    // index [n-1 , 0]

    for (int w = 0; w <= capacity; w++)
    {
        for (int indexx = 1; indexx <= index; indexx++)
        {
            int inc = 0;
            if (w >= wt[indexx])
            {
                inc = val[indexx] + dp[w - wt[indexx]][indexx - 1];
            }
            int exec = 0 + dp[w][indexx - 1];

            dp[w][indexx] = max(inc, exec);
        }
    }

    return dp[capacity][index];
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    // code here
    int index = wt.size() - 1;
    int ans = solve(W, val, wt, index);

    return ans;
}

int main()
{
    vector<int> val{1, 2, 4};
    vector<int> wt{4, 5, 6};
    int ans = knapsack(4, val, wt);
    cout << ans << endl;
    return 0;
}
