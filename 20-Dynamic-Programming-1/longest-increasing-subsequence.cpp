// https://leetcode.com/problems/longest-increasing-subsequence/submissions/1452895601/

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, int i, int lastIndex)
{
    if (i >= nums.size())
        return 0;

    int includeans = 0;
    if (lastIndex == -1 || nums[i] > nums[lastIndex])
    {
        includeans = 1 + solve(nums, i + 1, i);
    }
    int execludeans = solve(nums, i + 1, lastIndex);

    int finalans = max(includeans, execludeans);

    return finalans;
}
int lengthOfLIS(vector<int> &nums)
{
    int i = 0;
    int lastIndex = -1;
    return solve(nums, i, lastIndex);
}

// DP solution

int solveMem(vector<int> &nums, int i, int lastIndex, vector<vector<int>> &dp)
{
    if (i >= nums.size())
        return 0;

    if (dp[lastIndex + 1][i] != -1)
        return dp[lastIndex + 1][i];

    int includeans = 0;
    if (lastIndex == -1 || nums[i] > nums[lastIndex])
    {
        includeans = 1 + solveMem(nums, i + 1, i, dp);
    }
    int execludeans = solveMem(nums, i + 1, lastIndex, dp);

    dp[lastIndex + 1][i] = max(includeans, execludeans);

    return dp[lastIndex + 1][i];
}

int lengthOfLISMem(vector<int> &nums)
{
    int i = 0;
    int lastIndex = -1;
    // return solve (nums , i , lastIndex);
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, -1));
    return solveMem(nums, i, lastIndex, dp);
}

int main()
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    int ans = lengthOfLIS(nums);

    cout << "the ans is " << ans << endl;
    return 0;
}