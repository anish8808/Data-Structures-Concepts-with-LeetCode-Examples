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
            cout << i.first << " -{ ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << "}" << endl;
        }
    }

    bool cycleDetectUndirectedBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> que;
        unordered_map<int, int> paraent;

        que.push(src);
        visited[src] = true;
        paraent[src] = -1;

        while (!que.empty())
        {
            int frontNode = que.front();
            que.pop();
            for (auto nbr : addList[frontNode])
            {
                if (!visited[nbr])
                {
                    que.push(nbr);
                    visited[nbr] = true;
                    paraent[nbr] = frontNode;
                }
                // agar koi node visited true hain aur wo node jis node k adjlist me h uska parent nahi hain
                else if (visited[nbr] == true && nbr != paraent[frontNode])
                {
                    // cycle detected
                    return true;
                }
            }
        }
        // no cycle is detected
        return false;
    }
};
int main()
{

    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 4, 0);

    g.addEdge(2, 3, 0);
    g.printGraph();
    int n = 5;
    // this is we have to take care for disconnected graph
    // handeling disconnected componenet is very very important
    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.cycleDetectUndirectedBFS(i, visited);
            if (ans == true)
                break;
        }
    }
    if (ans)
    {
        cout << "cycle Detected " << endl;
    }
    else
    {
        cout << "cycle not detected " << endl;
    }

    return 0;
}