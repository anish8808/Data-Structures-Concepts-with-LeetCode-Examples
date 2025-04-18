// https://leetcode.com/problems/range-sum-of-bst/description/
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

void solve(TreeNode *root, int low, int high, int &ans)
{
    if (root == NULL)
        return;

    if (root->val >= low && root->val <= high)
    {
        ans = ans + root->val;
        solve(root->left, low, high, ans);
        solve(root->right, low, high, ans);
    }
    else if (root->val < low)
    {
        solve(root->right, low, high, ans);
    }
    else
    {
        solve(root->left, low, high, ans);
    }
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    solve(root, low, high, ans);
    return ans;
}
int main()
{
    TreeNode *root = createTree();
    int low = 5;
    int high = 7;
    int ans = rangeSumBST(root, low, high);
    cout << ans << endl;
    return 0;
}