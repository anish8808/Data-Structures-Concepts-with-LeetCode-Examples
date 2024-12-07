// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
    while (start <= end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
void rotate(vector<int> &nums, int k)
{
    if (nums.size() == 1)
    {
        return;
    }
    if (k > nums.size())
    {
        k = k % nums.size();
    }
    reverse(nums, 0, nums.size() - k - 1);
    reverse(nums, nums.size() - k, nums.size() - 1);
    reverse(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    for (auto i : nums)
    {
        cout << i << " ";
    }

    return 0;
}