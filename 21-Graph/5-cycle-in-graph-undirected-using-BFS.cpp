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

    bool cycleDetectionBFS(int src, unordered_map<int, bool> &visited)
    {

        unordered_map<int, int> paraents;
        queue<int> que;
        que.push(src);
        visited[src] = true;
        paraents[src] = -2;
        cout << "BFS" << endl;
        while (!que.empty())
        {
            int frontNode = que.front();
            cout << frontNode << " ";
            que.pop();
            auto it = adjList[frontNode];
            for (auto nbr : it)
            {
                if (!visited[nbr])
                {
                    que.push(nbr);
                    visited[nbr] = true;
                    paraents[nbr] = frontNode;
                }
                else if (visited[nbr] && visited[frontNode] != nbr)
                {
                    // if the node is already visited and paraents is different then its cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool cycleDetectionDFS(int src, unordered_map<int, bool> &visited, int paraents)
    {
        visited[src] = true;
        auto it = adjList[src];
        for (auto nbr : it)
        {
            if (!visited[nbr])
            {
                bool ans = cycleDetectionDFS(nbr, visited, src);
                if (ans == true)
                    return true;
            }
            else if (visited[nbr] && nbr != paraents)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Graph g;
    unordered_map<int, bool> visited;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);
    g.printGraph();
    int n = 3; // total number of node
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans = g.cycleDetectionBFS(i, visited);
            if (ans == true)
            {
                cout << "cycle is detcted" << endl;
                break;
            }
        }
    }
    if (ans == false)
        cout << "cycle is not present" << endl;

    // calling for dfs
    cout << "DFS" << endl;
    bool ansdfs = false;
    int paraent = -1;
    unordered_map<int, bool> visiteddfs;
    for (int i = 1; i <= n; i++)
    {
        if (!visiteddfs[i])
        {
            ansdfs = g.cycleDetectionDFS(i, visiteddfs, paraent);

            if (ansdfs)
            {
                cout << "detected cycle through DFS";
                break;
            }
        }
    }
    if (ansdfs == false)
        cout << "cycle is not present using dfs " << endl;

    return 0;
}