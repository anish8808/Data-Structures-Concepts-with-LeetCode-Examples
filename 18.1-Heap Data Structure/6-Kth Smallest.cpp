// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>

using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    // code here

    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int main()
{
    vector<int> nums{1, 4, 5, 22, 2, 3};
    int k = 3;
    int ans1 = kthSmallest(nums, k);

    cout << ans1 << " " << endl;

    return 0;
}