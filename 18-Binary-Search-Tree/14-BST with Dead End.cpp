// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void buildBST(TreeNode *&root, int val)
{
    if (root == NULL)
        root = new TreeNode(val);
    else
    {
        if (val < root->val)
        {
            buildBST(root->left, val);
        }
        else
        {
            buildBST(root->right, val);
        }
    }
}
TreeNode *createTree()
{
    cout << "enter the value for node " << endl;
    int val;
    cin >> val;
    TreeNode *root = NULL;
    while (val != -1)
    {
        buildBST(root, val);
        cout << "enter the value for node " << endl;
        cin >> val;
    }

    return root;
}
bool solve(TreeNode *root, unordered_map<int, int> &map)
{
    if (root == NULL)
        return false;

    map[root->val] = 1;
    if (root->left == NULL && root->right == NULL)
    {
        int x1 = root->val + 1;
        int x2 = root->val - 1 == 0 ? root->val : root->val - 1;
        if (map.find(x1) != map.end() && map.find(x2) != map.end())
            return true;
        else
            return false;
    }
    bool ansleft = solve(root->left, map);
    bool ansright = solve(root->right, map);

    return ansleft || ansright;
}
bool isDeadEnd(TreeNode *root)
{
    unordered_map<int, int> map;
    return solve(root, map);
}

int main()
{
    TreeNode *root = createTree();
    int ans = isDeadEnd(root);
    cout << ans << endl;
    return 0;
}