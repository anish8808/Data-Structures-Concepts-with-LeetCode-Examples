// https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int solveMem(vector<int> &nums, vector<int> &dp, int i)
{
    if (i >= nums.size())
        return false;

    if (i == nums.size() - 1)
        return true;

    if (nums[i] == 0)
        return false;

    if (dp[i] != -1)
        return dp[i];

    for (int jump = 1; jump <= nums[i]; jump++)
    {
        if (solveMem(nums, dp, i + jump))
        {
            return dp[i] = true;
        }
    }

    return dp[i] = false;
}

bool canJump(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();
    vector<int> dp(n + 10, -1);
    bool ans = solveMem(nums, dp, i);
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    bool ans = canJump(nums);
    cout << "jump Possible--> " << ans << endl;

    return 0;
}