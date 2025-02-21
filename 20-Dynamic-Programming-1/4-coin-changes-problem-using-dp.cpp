#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
int solve(vector<int> &arr, int target, vector<int> &dp)
{
    if (target == 0)
        return 0; // Base case: no coins needed for target 0
    if (target < 0)
        return INT_MAX; // Base case: invalid target

    // Check if already computed
    if (dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;
    for (int coin : arr)
    {
        int ans = solve(arr, target - coin, dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    return dp[target] = mini; // Store result and return
}

// Recursive function with memoization
int solveDP(vector<int> &arr, int target, vector<int> &dp)
{
    if (target == 0)
        return 0; // Base case: no coins needed for target 0
    if (target < 0)
        return INT_MAX; // Base case: invalid target

    // Check if already computed
    if (dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;
    for (int coin : arr)
    {
        int ans = solve(arr, target - coin, dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    return dp[target] = mini; // Store result and return
}

int main()
{
    vector<int> arr{1, 2, 3};
    int target = 5;

    // DP table to store results for subproblems
    vector<int> dp(target + 1, -1);

    int ans = solve(arr, target, dp);

    if (ans == INT_MAX)
        cout << "No solution possible to reach the target money." << endl;
    else
        cout << "Minimum coins needed to reach the target money is = " << ans << endl;

    return 0;
}
