// https://leetcode.com/problems/count-complete-tree-nodes/description/

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
int leftHeight(TreeNode *root)
{
    int count = 0;
    while (root)
    {
        count++;
        root = root->left;
    }
    return count;
}
int rightHeigh(TreeNode *root)
{
    int count = 0;
    while (root)
    {
        count++;
        root = root->right;
    }
    return count;
}

int leftHeight(TreeNode *root)
{
    int count = 0;
    while (root)
    {
        count++;
        root = root->left;
    }
    return count;
}
int rightHeigh(TreeNode *root)
{
    int count = 0;
    while (root)
    {
        count++;
        root = root->right;
    }
    return count;
}
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = leftHeight(root);
    int right = rightHeigh(root);
    if (left == right)
        return (1 << left) - 1;

    int lans = countNodes(root->left);
    int rans = countNodes(root->right);
    return 1 + lans + rans;
}
int main()
{
    TreeNode *root = createTree();
    int ans = countNodes(root);
    cout << ans << " ";
    return 0;
}