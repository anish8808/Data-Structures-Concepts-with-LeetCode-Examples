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

    void bfsTraversal(int src)
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

    void dfs(int node, unordered_map<int, bool> &visited)
    {
        // base condition
        if (visited[node])
        {
            return;
        }

        cout << node << " ";
        if (!visited[node])
        {
            visited[node] = true;
            for (auto it : addList[node])
            {
                int newNode = it.first;
                dfs(newNode, visited);
            }
        }
    }

    void dfsTraversal(int node)
    {
        unordered_map<int, bool> visited;

        dfs(node, visited);
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 3, 3, 1);
    g.addEdge(0, 5, 3, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 5, 3, 1);
    g.addEdge(3, 5, 3, 1);
    g.addEdge(5, 4, 3, 1);
    g.addEdge(5, 6, 3, 1);
    g.addEdge(4, 1, 3, 1);
    g.addEdge(6, 1, 3, 1);
    g.bfsTraversal(0);
    cout << endl;
    g.dfsTraversal(0);
    return 0;
}