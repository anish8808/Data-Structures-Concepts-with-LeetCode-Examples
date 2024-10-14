#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> addList;
    void addEgdes(int u, int v, int direction)
    {
        if (direction == 1)
        {

            addList[u].push_back(v);
        }
        else
        {
            addList[u].push_back(v);
            addList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : addList)
        {
            cout << i.first << " {";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << " }" << endl;
        }
    }

    void BFSAlgo(int node)
    {
        queue<int> que;
        unordered_map<int, bool> visited;
        que.push(node);
        visited[node] = true;
        cout << "BFS: ";
        while (!que.empty())
        {
            int front = que.front();
            cout << front << " ";
            que.pop();
            for (auto i : addList[front])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
    }

    void DFS(int node, unordered_map<int, bool> &visited)
    {
        if (visited[node])
        {
            return;
        }

        cout << node << " ";
        visited[node] = true;
        for (auto i : addList[node])
        {
            DFS(i, visited);
        }
    }

    void DFSalgo(int node)
    {
        unordered_map<int, bool> visited;
        cout << "DFS:";
        DFS(node, visited);
    }
};

int main()
{
    Graph g;
    g.addEgdes(0, 1, 1);
    g.addEgdes(0, 2, 1);
    g.addEgdes(1, 3, 1);
    g.addEgdes(2, 3, 1);
    g.addEgdes(3, 4, 1);
    g.printGraph();
    g.BFSAlgo(0);
    g.DFSalgo(0);
    return 0;
}