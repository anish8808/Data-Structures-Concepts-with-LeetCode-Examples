#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> addList;
    void addEdge(int u, int v, int direction)
    {
        if (direction == 0)
        {
            addList[u].push_back(v);
            addList[v].push_back(u);
        }
        else
        {
            addList[u].push_back(v);
        }
    }
};

int main()
{
    Graph g;

    return 0;
}