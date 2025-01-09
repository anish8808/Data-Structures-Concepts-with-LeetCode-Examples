// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
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

void solve(TreeNode *root, vector<int> &ans, int &sum)
{
    if (root == NULL)
        return;

    solve(root->left, ans, sum);

    // processing the Inorder to store the value of Sum and strore the elements in increasing Order
    sum = sum + root->val;
    ans.push_back(root->val);

    solve(root->right, ans, sum);
}

TreeNode *setValToBst(TreeNode *root, vector<int> &nums, int &index)
{
    if (root == NULL)
        return NULL;

    root->left = setValToBst(root->left, nums, index);
    root->val = nums[index];
    index++;
    root->right = setValToBst(root->right, nums, index);

    return root;
}

TreeNode *bstToGst(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    vector<int> nums;
    int totalSum = 0;
    solve(root, nums, totalSum);

    for (int i = 0; i < nums.size(); i++)
    {
        int val = nums[i];
        nums[i] = totalSum;
        totalSum = totalSum - val;
    }
    int i = 0;
    root = setValToBst(root, nums, i);

    return root;
}

int main()
{
    TreeNode *root = createTree();
    root = bstToGst(root);
    return 0;
}