// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>

using namespace std;
class info
{
public:
    int data;
    int cIndex;
    int rIndex;

    info(int data, int rIndex, int cIndex)
    {
        this->data = data;
        this->cIndex = cIndex;
        this->rIndex = rIndex;
    }
};

class compare
{
public:
    bool operator()(info *a, info *b)
    {
        return (a->data) > (b->data);
    }
};

vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<info *, vector<info *>, compare> pq;
    int maxElement = INT_MIN;
    for (int row = 0; row < nums.size(); row++)
    {
        if (nums[row][0] > maxElement)
            maxElement = nums[row][0];
        info *temp = new info(nums[row][0], row, 0);
        pq.push(temp);
    }
    int start = pq.top()->data;
    int end = maxElement;
    int minRange = maxElement - pq.top()->data;
    // now we will check till k elements
    while (!pq.empty())
    {
        info *top = pq.top();
        int data = top->data;
        int rIndex = top->rIndex;
        int cIndex = top->cIndex;
        pq.pop();

        int range = maxElement - top->data;
        if (minRange > range)
        {
            start = top->data;
            end = maxElement;
            minRange = range;
        }

        if (cIndex + 1 < nums[rIndex].size())
        {
            int element = nums[rIndex][cIndex + 1];
            info *temp = new info(element, rIndex, cIndex + 1);
            maxElement = max(maxElement, element);
            pq.push(temp);
        }
        else
        {
            break;
        }
    }

    return {start, end};
}
int main()
{
    vector<vector<int>> nums{{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    vector<int> ans = smallestRange(nums);

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}