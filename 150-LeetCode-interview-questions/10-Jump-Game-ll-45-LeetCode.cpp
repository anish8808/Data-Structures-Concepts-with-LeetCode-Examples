// https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size() - 1) // If already at or beyond the last index
        return 0;

    if (dp[i] != -1) // Return cached result
        return dp[i];

    int minSteps = INT_MAX; // Initialize to max value
    for (int jump = 1; jump <= nums[i]; jump++)
    {
        int nextIndex = i + jump;
        if (nextIndex < nums.size())
        {
            int steps = solve(nums, nextIndex, dp);
            if (steps != INT_MAX)
            { // Update minimum steps
                minSteps = min(minSteps, 1 + steps);
            }
        }
    }

    return dp[i] = minSteps;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, 0, dp);
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int ans = jump(nums);
    cout << "Minimun jump Possible--> " << ans << endl;

    return 0;
}