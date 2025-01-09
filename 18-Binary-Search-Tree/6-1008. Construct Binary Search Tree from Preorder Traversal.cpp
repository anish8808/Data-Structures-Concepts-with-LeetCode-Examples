// leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
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

TreeNode *createBST(TreeNode *&root, int val)
{
    // 1st case if the node is leat node
    if (root == NULL)
    {
        TreeNode *node = new TreeNode(val);
        return node;
    }
    if (root->val > val)
        root->left = createBST(root->left, val);
    else
        root->right = createBST(root->right, val);

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.size() == 0)
        return NULL;

    TreeNode *root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); i++)
    {
        root = createBST(root, preorder[i]);
    }

    return root;
}

int main()
{
    TreeNode *root = createTree();
    vector<int> preorder{8, 5, 1, 7, 10, 12};
    TreeNode *ans = bstFromPreorder(preorder);
    return 0;
}