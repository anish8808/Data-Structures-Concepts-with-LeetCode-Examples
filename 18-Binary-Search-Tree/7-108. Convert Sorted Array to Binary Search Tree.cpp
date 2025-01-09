// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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

TreeNode *solve(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;

    // create the treeNode
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    // call the left tree
    root->left = solve(nums, start, mid - 1);

    // call the right tree
    root->right = solve(nums, mid + 1, end);

    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;
    int start = 0;
    int end = nums.size() - 1;
    TreeNode *root = solve(nums, start, end);
    return root;
}

int main()
{
    TreeNode *root = createTree();
    vector<int> preorder{1, 2, 3, 4, 5};
    TreeNode *ans = sortedArrayToBST(preorder);
    return 0;
}