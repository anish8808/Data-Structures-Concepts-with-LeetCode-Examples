// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>

using namespace std;
int minCost(vector<int> &arr)
{
    // code here
    // taking mean Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < arr.size(); i++)
    {
        minHeap.push(arr[i]);
    }
    int sum = 0;
    while (minHeap.size() > 1)
    {

        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        sum = sum + (a + b);
        minHeap.push(a + b);
    }

    return sum;
}

int main()
{
    vector<int> nums{1, 4, 5, 22, 2, 3};
    int ans1 = minCost(nums);

    cout << ans1 << " " << endl;

    return 0;
}