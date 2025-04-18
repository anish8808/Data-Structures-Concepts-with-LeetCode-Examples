// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>

using namespace std;
class Info
{
public:
    int data;
    int cIndex;
    int rIndex;

    Info(int data, int rIndex, int cIndex)
    {
        this->data = data;
        this->cIndex = cIndex;
        this->rIndex = rIndex;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return (a->data) > (b->data);
    }
};

// Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    priority_queue<Info *, vector<Info *>, compare> pq;
    for (int row = 0; row < arr.size(); row++)
    {
        int element = arr[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }

    while (!pq.empty())
    {
        Info *front = pq.top();
        pq.pop();
        int frontdata = front->data;
        int rIndex = front->rIndex;
        int cIndex = front->cIndex;
        ans.push_back(frontdata);

        if (cIndex + 1 < arr[0].size())
        {
            int element = arr[rIndex][cIndex + 1];
            Info *temp = new Info(element, rIndex, cIndex + 1);
            pq.push(temp);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums{{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    vector<int> ans = mergeKArrays(nums, 3);

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}