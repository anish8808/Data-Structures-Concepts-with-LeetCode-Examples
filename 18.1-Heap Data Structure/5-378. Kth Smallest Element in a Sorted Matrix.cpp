// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include <bits/stdc++.h>

using namespace std;

int kthSmallest(vector<vector<int>> &nums, int k)
{
    priority_queue<int> pq;
    int count = 0;
    int firstIndex = 0;
    int secondIndex = 0;
    // inserting k element in max heap
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == k)
            break;
        for (int j = 0; j < nums[0].size(); j++)
        {
            pq.push(nums[i][j]);
            firstIndex = i;
            secondIndex = j;
            count++;
            if (count == k)
                break;
        }
    }

    secondIndex++;
    for (int i = firstIndex; i < nums.size(); i++)
    {
        for (int j = secondIndex; j < nums[0].size(); j++)
        {
            if (nums[i][j] < pq.top())
            {
                pq.pop();
                pq.push(nums[i][j]);
            }
        }
        secondIndex = 0;
    }

    return pq.top();
}
int main()
{
    vector<vector<int>> nums{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    int ans1 = kthSmallest(nums, k);

    cout << ans1 << " " << endl;

    return 0;
}