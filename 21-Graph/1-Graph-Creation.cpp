#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction =0 --> undirected Graph
        // direction=1 --> direceted Graph

        if (direction == 0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
        {
            adjList[u].push_back(v);
        }
    }

    void PrintGraphList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " --> { ";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << " }" << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.PrintGraphList();
    return 0;
}