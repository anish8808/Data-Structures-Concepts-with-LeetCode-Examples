
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

pair<int, int> solve(TreeNode *root)
{
    if (root == NULL)
        return {0, 0};

    auto left = solve(root->left);
    auto right = solve(root->right);

    // including root val
    int a = root->val + left.second + right.second;

    // excluding currect root
    int b = max(left.first, left.second) + max(right.first, right.second);
    return {a, b};
}
int getMaxSum(TreeNode *root)
{
    auto ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    TreeNode *root = createTree();
    auto ans = getMaxSum(root);
    cout << ans << endl;
    return 0;
}
