// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// added

// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// added
#include <bits/stdc++.h>

using namespace std;

//------------->This Solution will take O(n) time and O(n) Space---->
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);

    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
}

//---->This solution will take O(n) time  but O(k) space complexity
int findKthLargestUsingMinHeap(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for (int i = 0; i < k; i++)
        min_pq.push(nums[i]);

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > min_pq.top())
        {
            min_pq.pop();
            min_pq.push(nums[i]);
        }
    }

    return min_pq.top();
}
int main()
{
    vector<int> nums{1, 4, 5, 22, 2, 3};
    int k = 3;
    int ans1 = findKthLargest(nums, k);
    int ans2 = findKthLargestUsingMinHeap(nums, k);

    cout << ans1 << " " << ans2 << endl;

    return 0;
}