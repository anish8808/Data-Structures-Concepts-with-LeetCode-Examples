#include <bits/stdc++.h>

using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{

    unordered_map<int, int> freqMap;

    long long maxSum = 0;
    long long currSum = 0;

    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        // stroring map freq
        freqMap[nums[right]]++;

        // adding currelement to currSum
        currSum = currSum + nums[right];

        // if cou
        if (right - left + 1 > k)
        {
            currSum = currSum - nums[left];
            freqMap[nums[left]]--;
            if (freqMap[nums[left]] == 0)
            {
                freqMap.erase(nums[left]);
            }
            left++;
        }

        if (freqMap.size() == k && right - left + 1 == k)
        {
            maxSum = max(currSum, maxSum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 9, 9};
    long long ans = maximumSubarraySum(nums, 3);
    cout << ans << endl;

    return 0;
}