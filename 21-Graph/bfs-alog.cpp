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
        unordered_map<int, bool> visited;
        queue<int> que;
        que.push(node);
        visited[node] = true;
        cout << "BFS" << endl;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                int front = que.front();
                que.pop();
                cout << front << " ";
                for (auto it : adjlist[front])
                {
                    if (!visited[it])
                    {
                        que.push(it);
                        visited[it] = true;
                    }
                }
            }
            cout << endl;
        }
    }

    void dfsHelper(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (int it : adjlist[src])
        {
            if (!visited[it])
                dfsHelper(it, visited);
        }
    }

    void DFS(int node)
    {
        unordered_map<int, bool> visited;
        cout << "DFS" << endl;
        for (int src = 0; src < node; src++) // always make sure the disconnected graphs as well
        {
            if (!visited[src])
            {
                dfsHelper(src, visited);
            }
        }
    }
};
int main()
{
    Graph G;
    G.addEdges(0, 3, 0);
    G.addEdges(0, 5, 0);
    G.addEdges(0, 2, 0);
    G.addEdges(3, 5, 0);
    G.addEdges(2, 5, 0);
    G.addEdges(5, 4, 0);
    G.addEdges(5, 6, 0);
    G.addEdges(4, 1, 0);
    G.addEdges(6, 1, 0);

    cout << "Printing BFS" << endl;
    G.BFS(0);
    G.DFS(0);
    cout << "Printing DFS " << endl;
    return 0;
}