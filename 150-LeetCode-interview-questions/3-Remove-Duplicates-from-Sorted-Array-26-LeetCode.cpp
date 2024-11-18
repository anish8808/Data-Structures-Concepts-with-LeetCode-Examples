// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int k = 0;
    nums[i] = nums[k];
    i++;
    while (i < nums.size())
    {
        if (nums[i] != nums[k])
        {
            k++;
            nums[k] = nums[i];
            i++;
        }
        else
        {
            i++;
        }
    }
    return k + 1;
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