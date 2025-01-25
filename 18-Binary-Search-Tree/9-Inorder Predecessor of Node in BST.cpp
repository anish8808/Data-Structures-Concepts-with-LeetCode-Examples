// https://leetcode.com/problems/validate-binary-search-tree/description/

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

TreeNode *findPredecessor(TreeNode *root, TreeNode *p)
{
    TreeNode *pred = 0;
    TreeNode *curr = root;

    while (curr)
    {
        if (curr->val < p->val)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    return pred;
}

int main()
{
    TreeNode *root = createTree();
    TreeNode *p = new TreeNode(6);
    TreeNode *ans = findPredecessor(root, p);
    return 0;
}