//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool detectCycleBFS(int src, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, int> &paraents)
    {
        queue<int> que;
        que.push(src);
        visited[src] = true;
        paraents[src] = -1;

        while (!que.empty())
        {
            int frontNode = que.front();
            que.pop();
            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    que.push(nbr);
                    paraents[nbr] = frontNode;
                }
                else if (visited[nbr] && nbr != paraents[frontNode])
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> adjList;

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        bool ans = false;
        unordered_map<int, int> paraents;
        unordered_map<int, bool> visited;

        for (int i = 0; i <= V; i++)
        {
            if (!visited[i])
            {
                ans = detectCycleBFS(i, adjList, visited, paraents);
                if (ans)
                {
                    break;
                }
            }
        }

        if (ans)
            return true;
        else
            return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    // cin.ignore();
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        // cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends