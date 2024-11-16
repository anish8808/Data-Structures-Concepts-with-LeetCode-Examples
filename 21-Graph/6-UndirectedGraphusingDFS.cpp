#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> addList;
    void addEdge(int u, int v, int direction)
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
            cout << i.first << "->{ ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << " }" << endl;
        }
    }
    bool cycleDetectionUsingDfs(int src, unordered_map<int, bool> &visited, int paraent)
    {
        visited[src] = true;
        for (auto nbr : addList[src])
        {
            if (!visited[nbr])
            {
                bool ans = cycleDetectionUsingDfs(nbr, visited, src);
                if (ans == true)
                    return true;
            }
            else if (visited[nbr] == true && nbr != paraent)
            {
                return true;
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.printGraph();
    return 0;
}