// https://www.interviewbit.com/problems/valid-bst-from-preorder/
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildBST(int &i, vector<int> &preorder, int low, int high)
{
    if (i >= preorder.size())
        return NULL;

    TreeNode *root = NULL;
    if (preorder[i] > low && preorder[i] < high)
    {
        root = new TreeNode(preorder[i++]);
        root->left = buildBST(i, preorder, low, root->val);
        root->right = buildBST(i, preorder, root->val, high);
    }

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int low = INT_MIN;
    int high = INT_MAX;
    int i = 0;
    return buildBST(i, preorder, low, high);
}

int main()
{
    vector<int> preorder{8, 1, 2, 4, 9, 10, 11, 23};
    TreeNode *ans = bstFromPreorder(preorder);
    return 0;
}