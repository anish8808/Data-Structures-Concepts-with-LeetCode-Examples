/*** 198. House Robber
Attempted
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400 ***/

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, int i, int &sum)
{
    if (i >= nums.size())
        return sum;

    sum = sum + nums[i];
    int ansinclude = solve(nums, i + 2, sum);
    sum = sum - nums[i];
    int ansexclude = solve(nums, i + 1, sum);

    int ans = max(ansinclude, ansexclude);

    return ans;
}
int rob(vector<int> &nums)
{
    int sum = 0;
    return solve(nums, 0, sum);
}

int solveMem(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
        return 0;

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ansinclude = nums[i] + solveMem(nums, i + 2, dp);
    int ansexclude = solveMem(nums, i + 1, dp);

    dp[i] = max(ansinclude, ansexclude);

    return dp[i];
}
int robMem(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solveMem(nums, 0, dp);
}

// using tabulation method
//  }
int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int ansinclude = nums[i] + dp[i + 2];
        int ansexclude = dp[i + 1];

        dp[i] = max(ansinclude, ansexclude);
    }

    return dp[0];
}

// solve Using with extra space optimization

int solveUsingOptimalSpace(vector<int> &nums)
{
    int n = nums.size();
    int next2 = 0;
    int next1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int include = nums[i] + next2;
        int exclude = next1;
        int curr = max(include, exclude);
        next2 = next1;
        next1 = curr;
    }
    return next1;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int ans = rob(nums);
    cout << "The maximum amount stolen is " << ans << endl;

    // using Dp memoiasation  method
    vector<int> numsMem{1, 2, 3, 1};
    ans = robMem(numsMem);
    cout << "BY DP The maximum amount stolen is " << ans << endl;

    // using tabulation method

    cout << "ans using tabulation method " << solveTab(numsMem);
    return 0;
}