#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjlist;

    void addEdges(int u, int v, bool direction)
    {
        if (direction)
        {
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        else
        {
            adjlist[u].push_back(v);
        }
    }

    void BFS(int node)
    {
        unordered_map<int, int> visited;
        queue<int> que;
        que.push(node);
        while (!que.empty())
        {
            list<int> nbr;
            int front = que.front();
            que.pop();
            nbr = adjlist[front];
        }
    }
};
int main()
{
    return 0;
}