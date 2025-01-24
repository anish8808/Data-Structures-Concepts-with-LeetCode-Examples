
// www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    // constructor while crearting node left and rigth node will be null
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *createTree()
{
    cout << "enter the value for node " << endl;
    int val;
    cin >> val;

    if (val == -1)
        return NULL;
    else
    {
        // valid value
        TreeNode *root = new TreeNode(val);
        cout << "adding left chilf for tree " << endl;
        root->left = createTree();
        cout << "adding right child node" << endl;
        root->right = createTree();

        return root;
    }
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    unordered_map<int, vector<pair<int, int>>> map;
    queue<pair<TreeNode *, pair<int, int>>> que;
    int minLimit = INT_MAX;
    int maxLimit = INT_MIN;

    que.push({root, {0, 0}});
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            pair<TreeNode *, pair<int, int>> pair;
            pair = que.front();
            que.pop();
            TreeNode *frontNode = pair.first;
            int col = pair.second.second;
            int row = pair.second.first;
            minLimit = min(minLimit, col);
            maxLimit = max(maxLimit, col);
            map[col].push_back({row, frontNode->val});
            if (frontNode->left != NULL)
            {
                que.push({frontNode->left, {row + 1, col - 1}});
            }
            if (frontNode->right != NULL)
            {
                que.push({frontNode->right, {row + 1, col + 1}});
            }
        }
    }

    if (maxLimit == INT_MIN || minLimit == INT_MAX)
        return ans;

    for (int i = minLimit; i <= maxLimit; i++)
    {
        vector<int> eachans;
        sort(map[i].begin(), map[i].end());
        for (auto j : map[i])
        {
            eachans.push_back(j.second);
        }

        ans.push_back(eachans);
    }

    return ans;
}

int main()
{
    TreeNode *root = createTree();
    vector<vector<int>> ans = verticalTraversal(root);
    return 0;
}
