// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/// leetcode.com/problems/path-sum-ii/
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

TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int &preOrder, int inOrderStart,
                     int inOrdereEnd, int size, unordered_map<int, int> &mapp)
{
    if (preOrder > size)
        return NULL;

    if (inOrderStart > inOrdereEnd)
        return NULL;

    // logic
    int ele = preorder[preOrder];
    preOrder++;
    // int getPositioninInorder = getpos(inorder ,ele); //instead of this we will use map to reduce time complexity

    int getPositioninInorder = mapp[ele];
    TreeNode *root = new TreeNode(ele);
    root->left = createTree(preorder, inorder, preOrder, inOrderStart, getPositioninInorder - 1, size, mapp);
    root->right = createTree(preorder, inorder, preOrder, getPositioninInorder + 1, inOrdereEnd, size, mapp);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int inOrderStart = 0;
    int inOrdereEnd = inorder.size() - 1;
    int preOrder = 0; // root elememt
    int size = preorder.size() - 1;
    unordered_map<int, int> mapp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mapp[inorder[i]] = i;
    }
    return createTree(preorder, inorder, preOrder, inOrderStart, inOrdereEnd, size, mapp);
}

void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        cout << " null";
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> preorder{3, 9, 20, 15, 7};

    TreeNode *root = buildTree(preorder, inorder);
    printTree(root);
    return 0;
}