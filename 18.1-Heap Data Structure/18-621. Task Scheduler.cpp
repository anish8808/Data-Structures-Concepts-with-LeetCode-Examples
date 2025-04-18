
#include <bits/stdc++.h>

using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> freqMap;
    for (auto c : tasks)
        freqMap[c]++;

    priority_queue<int> pq;
    for (auto i : freqMap)
        pq.push(i.second);

    int time = 0;

    while (!pq.empty())
    {
        int intervral = n + 1;
        vector<int> temp;
        while (intervral > 0 && !pq.empty())
        {
            int top = pq.top();
            pq.pop();
            time++;
            intervral--;
            top--;
            if (top > 0)
                temp.push_back(top);
        }

        // process the remaning process
        for (auto i : temp)
            pq.push(i);

        if (!pq.empty())
            time = time + intervral;
    }

    return time;
}

int main()
{
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int ans = leastInterval(tasks, n);
    return 0;
}