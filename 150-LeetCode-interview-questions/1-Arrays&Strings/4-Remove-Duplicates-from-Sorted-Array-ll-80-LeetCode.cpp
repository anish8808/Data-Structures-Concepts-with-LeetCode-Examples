// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    int count = 0;
    int prev = nums[0];
    nums[k++] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == prev && count < 1)
        {
            nums[k++] = nums[i];
            prev = nums[i];
            count++;
        }
        else if (nums[i] != prev)
        {
            count = 0;
            nums[k++] = nums[i];
            prev = nums[i];
        }
    }
    return k;
}

int main()
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    removeDuplicates(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}