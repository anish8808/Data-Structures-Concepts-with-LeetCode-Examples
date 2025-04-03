#include <bits/stdc++.h>

using namespace std;

int solveUsingRec(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return k + (k * (k - 1));

    int ans = (k - 1) * (solveUsingRec(n - 1, k) + solveUsingRec(n - 2, k));

    return ans;
}

// 1-d solution DP memoisation
int solveUsingMem(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return k + (k * (k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (k - 1) * (solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp));

    return dp[n];
}

// dp solution tabulation method

int solveUsingTab(int n, int k)
{
    vector<int> dp(n + 1, 0);

    // base case first
    dp[1] = k;

    // base case second
    dp[2] = k + (k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

// space optimization
int solveUsingSpaceOptimixation(int n, int k)
{

    // base case first
    int prev = k;

    // base case second
    int curr = k + (k * (k - 1));

    if (n == 1)
        return prev;

    if (n == 2)
        return curr;

    for (int i = 3; i <= n; i++)
    {
        int next = (k - 1) * (curr + prev);
        prev = curr;
        curr = next;
    }
    return curr;
}

int countWays(int n, int k)
{
    int ans = solveUsingRec(n, k);

    return ans;
}
int main()
{
    int ans = countWays(4, 3);
    cout << ans;
    return 0;
}