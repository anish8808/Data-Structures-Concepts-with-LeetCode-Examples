// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

TreeNode *createTree(vector<int> &inorder, vector<int> &postorder, int &postOrderEnd, int inOrderStart, int inOrderEnd, int size, unordered_map<int, int> &mapp)
{
    if (postOrderEnd < 0)
        return NULL;
    if (inOrderStart > inOrderEnd)
        return NULL;

    // LOGIC
    int ele = postorder[postOrderEnd];
    TreeNode *root = new TreeNode(ele);
    postOrderEnd--;
    int positioninInorder = mapp[ele];
    root->right = createTree(inorder, postorder, postOrderEnd, positioninInorder + 1, inOrderEnd, size, mapp);
    root->left = createTree(inorder, postorder, postOrderEnd, inOrderStart, positioninInorder - 1, size, mapp);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int postOrderEnd = postorder.size() - 1;
    int inOrderStart = 0;
    int inOrderEnd = inorder.size() - 1;
    int size = inorder.size() - 1;
    unordered_map<int, int> mapp;
    for (int i = 0; i < inorder.size(); i++)
        mapp[inorder[i]] = i;

    return createTree(inorder, postorder, postOrderEnd, inOrderStart, inOrderEnd, size, mapp);
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
    vector<int> postorder{9, 15, 7, 20, 3};

    TreeNode *root = buildTree(inorder, postorder);
    printTree(root);
    return 0;
}