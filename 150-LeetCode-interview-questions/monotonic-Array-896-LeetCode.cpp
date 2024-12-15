// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Second Easy solution

bool isMonotonic(vector<int> &nums)
{
    if (nums[nums.size() - 1] - nums[0] > 0)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] <= nums[i + 1])
                continue;
            else
                return false;
        }
    }
    else
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
                continue;
            else
                return false;
        }
    }
    return true;
}
int main()
{
    vector<int> nums{1, 2, 0, 0, 4, 3, 3, 4, 3};
    cout << isMonotonic(nums) << endl;

    return 0;
}