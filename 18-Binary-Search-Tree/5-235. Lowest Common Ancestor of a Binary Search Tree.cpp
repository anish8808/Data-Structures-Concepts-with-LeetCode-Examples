// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;

    // 1st case if root is less than p and greater then q then that will LCA of that tree

    if (root->val >= (p->val) && root->val <= (q->val))
        return root;

    if (root->val >= (q->val) && root->val <= (p->val))
        return root;

    if (root->val > (p->val) && root->val > (q->val))
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}

int main()
{
    TreeNode *root = createTree();
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(2);
    TreeNode *ans = lowestCommonAncestor(root, p, q);
    cout << ans->val << endl;
    return 0;
}