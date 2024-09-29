#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    // first int is u , second int v , third is weight
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction =0 --> undirected Graph
        // direction=1 --> direceted Graph

        if (direction == 0)
        {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
        else
        {
            adjList[u].push_back({v, weight});
        }
    }

    void PrintGraphList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " : { ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << " " << j.second << ")";
            }
            cout << " ,}" << endl;
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
    g.PrintGraphList();
    return 0;
}