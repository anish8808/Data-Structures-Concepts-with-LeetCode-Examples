// there is  two alogirits to detect cycle in the graph
/*
1 - undirected graph --2 algo
    1- DFS
    2- BFS
2 - directed graph --2 algo
    1- DFS
    2- BFS

--> checking the cycle in the graph
        cycle means if we satrt fromt the node the after following on path we will come to the same Node
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool check)
    {
        if (check == true) // directed so in check ==1
        {
            adjList[u].push_back(v);
        }
        else
        {
            // if graph is undirected then it will travel both the side either u to v or v to u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto it : adjList)
        {
            // printing the graph
            cout << it.first << "-->";
            for (auto i : it.second)
            {
                cout << i << " ";
            }

            cout << endl;
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
    g.printGraph();
    return 0;
}