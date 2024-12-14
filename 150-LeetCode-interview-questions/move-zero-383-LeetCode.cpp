// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    int last = nums.size() - 1;
    int i = 0;
    while (i <= last)
    {
        if (nums[i] == val)
        {
            if (nums[last] == val)
            {
                last--;
                count++;
            }
            else
            {
                swap(nums[i], nums[last]);
                count++;
                i++;
                last--;
            }
        }
        else
        {
            i++;
        }
    }

    return nums.size() - count;
}

// Second Easy solution

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    while (i < nums.size())
    {
        if (nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
        i++;
    }
    while (j < nums.size())
    {
        nums[j] = 0;
        j++;
    }
}
int main()
{
    vector<int> nums{1, 2, 0, 0, 4, 3, 3, 4, 3};
    moveZeroes(nums);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}