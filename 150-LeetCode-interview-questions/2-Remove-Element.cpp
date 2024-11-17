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

int removeElement2(vector<int> &nums, int val)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}
int main()
{
    vector<int> nums{1, 2, 3, 4, 4, 3, 3, 4, 3};
    int target = 3;
    cout << "ans is " << removeElement(nums, target) << endl;
    cout << "ans is from second solution " << removeElement2(nums, target) << endl;
    return 0;
}