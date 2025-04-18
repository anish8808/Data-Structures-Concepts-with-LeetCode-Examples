// https://leetcode.com/problems/balance-a-binary-search-tree/description/
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

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

TreeNode *solve(vector<int> &ans, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    TreeNode *root = new TreeNode(ans[mid]);

    root->left = solve(ans, start, mid - 1);
    root->right = solve(ans, mid + 1, end);

    return root;
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    int start = 0;
    int end = ans.size() - 1;
    return solve(ans, start, end);
}

int main()
{
    TreeNode *root = createTree();
    TreeNode *ans = balanceBST(root);
    return 0;
}