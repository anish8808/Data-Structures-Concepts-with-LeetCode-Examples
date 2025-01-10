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

bool solve(TreeNode *root, long long minVal, long long maxVal)
{

    if (root == NULL)
        return true;

    // check the Node value
    if (root->val <= minVal || root->val >= maxVal)
        return false;

    bool left = solve(root->left, minVal, root->val);
    bool right = solve(root->right, root->val, maxVal);
    return left && right;
}
bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    long long minValue = LLONG_MIN;
    long long maxValue = LLONG_MAX;
    bool ans = solve(root, minValue, maxValue);
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    bool ans = isValidBST(root);
    return 0;
}