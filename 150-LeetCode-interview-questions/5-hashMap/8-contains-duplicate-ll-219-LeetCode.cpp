#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mapp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mapp.count(nums[i]))
        {
            if (abs(mapp[nums[i]] - i) <= k)
                return true;
        }
        mapp[nums[i]] = i;
    }
    return false;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int k = 3;
    bool ans = containsNearbyDuplicate(nums, k);
    cout << ans << endl;
}