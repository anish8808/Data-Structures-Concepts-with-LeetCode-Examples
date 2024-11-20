// https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150
#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> map;
    int ans;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]] = map[nums[i]] + 1;
        if (map[nums[i]] > nums.size() / 2)
            ans = nums[i];
    }

    // for(auto i : map)
    // {
    //     if(i.second>nums.size()/2)
    //         return i.first;
    // }
    return ans;
}

int main()
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = majorityElement(nums);
    cout << ans << endl;

    return 0;
}