#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

int main()
{
    Graph g;
    g.addEdgesDirected(1, 2);
    g.addEdgesDirected(1, 3);
    g.addEdgesDirected(3, 4);
    g.addEdgesDirected(4, 5);
    g.addEdgesDirected(5, 6);
    g.addEdgesDirected(6, 2);
    g.addEdgesDirected(6, 2);

    bool ans = false;
    int n = 6;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> path;
    g.printGraph();
    cout << "Cycle detection using DFS" << endl;
    // calling for dfs
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans = g.CycleDetectionDirectedGraph(i, visited, path);
            if (ans)
            {
                cout << "cycle is detected" << endl;
                break;
            }
        }
    }
    cout << "cycle is not detected" << endl;
    return 0;
}