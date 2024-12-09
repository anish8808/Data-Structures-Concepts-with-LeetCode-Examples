#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;
    map<int, int> mapp;
    for (int i = 0; i < nums.size(); i++)
    {
        mapp[nums[i]]++;
    }
    int count = 0;
    int ans = 0;
    auto first = mapp.begin();
    int ithelement = first->first;
    for (auto i : mapp)
    {
        if (abs(i.first - ithelement) == 1)
        {
            count++;
            ans = max(ans, count);
            ithelement = i.first;
        }
        else
        {
            count = 0;
            ithelement = i.first;
        }
    }
    return ans + 1;
}

int main()
{
    vector<int> nums{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    int ans = longestConsecutive(nums);
    cout << "ans" << ans << endl;
}