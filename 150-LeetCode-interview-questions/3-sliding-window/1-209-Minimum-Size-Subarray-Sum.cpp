
#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int minlensubArray = 0;
    int count = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        count = count + nums[i];
        minlensubArray++;
        if (count >= target)
            break;
    }

    return count >= target ? minlensubArray : 0;
}

int main()
{
    vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = minSubArrayLen(nums, 7);
    cout << ans << endl;
}