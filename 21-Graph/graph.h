#if !defined(GRAPH_H)
#define GRAPH_H

#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdgesDirected(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void addEdgesUnDirected(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph()
    {
        cout << "Prinitng the graph" << endl;
        for (auto it : adjList)
        {
            cout << it.first << ": { ";
            for (int i : it.second)
            {
                cout << i << " ";
            }
            cout << "}";
            cout << endl;
        }
    }

    bool CycleDetectionDirectedGraph(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &path)
    {
        visited[src] = true;
        path[src] = true;

        for (auto i : adjList[src])
        {
            if (!visited[i])
            {
                bool ans = CycleDetectionDirectedGraph(i, visited, path);
                if (ans)
                    return true;
            }
            else if (visited[i] == true && path[i] == true)
            {
                // if the node is already visited and path is true then its cycle
                return true;
            }
            {
                return true;
            }
        }

        path.erase(src);
        return false;
    }
};

#endif