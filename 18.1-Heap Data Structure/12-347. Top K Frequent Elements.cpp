// https://leetcode.com/problems/top-k-frequent-elements/
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freqMap;
    for (int i = 0; i < nums.size(); i++)
        freqMap[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto i : freqMap)
    {
        pq.push({i.second, i.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        pair<int, int> ele = pq.top();
        ans.push_back(ele.second);
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> ans = {1, 3, 2, 7, 6, 5};
    int k = 3;
    vector<int> nums = topKFrequent(ans, k);
    for (auto i : nums)
        cout << i << endl;
    return 0;
}