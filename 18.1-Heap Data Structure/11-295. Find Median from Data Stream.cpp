#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = INT_MIN;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() && minHeap.empty())
        {
            maxHeap.push(num);
            median = double(num);
        }
        else
        {
            // if both heaps are eqaul then just insert the element and store the median to bigger top
            if (maxHeap.size() == minHeap.size())
            {
                if (median < num)
                {
                    // enter to right heap that is minHeap and top will be medain
                    minHeap.push(num);
                    median = double(minHeap.top());
                }
                else
                {
                    // enter to left heap that is maxHeap and top will be medain
                    maxHeap.push(num);
                    median = double(maxHeap.top());
                }
            }
            else if (maxHeap.size() == minHeap.size() + 1)
            {
                if (median < double(num))
                {
                    // enter to right heap that is minHeap
                    minHeap.push(num);
                }
                else
                {
                    // enter to left heap that is maxHeap
                    int top = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(top);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else
            {
                if (median < double(num))
                {
                    // enter to right heap that is minHeap
                    int top = minHeap.top();
                    minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(top);
                }
                else
                {
                    // enter to left heap that is maxHeap
                    maxHeap.push(num);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
    }

    double findMedian()
    {
        return median;
    }
};

int main()
{
    return 0;
}