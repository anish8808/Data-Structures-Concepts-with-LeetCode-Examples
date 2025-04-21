//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// } Driver Code Ends
class Solution
{
public:
    bool cyclecheckDFS(int src, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int paraents)
    {
        visited[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool ans = cyclecheckDFS(nbr, adjList, visited, src);
                if (ans)
                    return true;
            }
            else if (visited[nbr] && nbr != paraents)
            {
                return true;
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
        int paraents = -1;
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                ans = cyclecheckDFS(i, adjList, visited, paraents);
                if (ans)
                    break;
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
    cin.ignore();
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        cin.ignore();
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