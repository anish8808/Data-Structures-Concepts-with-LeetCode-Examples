#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> addList;
    void addEdge(int u, int v, int weight, int direction)
    {
        if (direction == 0)
        {
            addList[u].push_back({v, weight});
            addList[v].push_back({u, weight});
        }
        else
        {
            addList[u].push_back({v, weight});
        }
    }

    void PrintLevelOrder(int src)
    {
        queue<int> que;
        unordered_map<int, bool> visited;
        que.push(src);
        visited[src] = true;
        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            cout << front << " ";
            for (auto it : addList[front])
            {
                int node = it.first;
                if (!visited[node])
                {
                    que.push(node);
                    visited[node] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 10, 1);
    g.addEdge(0, 2, 20, 1);
    g.addEdge(1, 2, 30, 1);
    g.addEdge(2, 3, 40, 1);
    g.PrintLevelOrder(0);

    return 0;
}