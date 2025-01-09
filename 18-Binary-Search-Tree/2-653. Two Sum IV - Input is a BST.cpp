// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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

void solve(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
        return;

    solve(root->left, nums);
    nums.push_back(root->val);
    solve(root->right, nums);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> nums;
    solve(root, nums);
    int start = 0;
    int end = nums.size() - 1;
    bool check = false;
    while (start < end)
    {
        if (nums[start] + nums[end] == k)
        {
            check = true;
            break;
        }
        else if (nums[start] + nums[end] > k)
            end--;
        else
            start++;
    }

    return check;
}

int main()
{
    TreeNode *root = createTree();
    bool ans = findTarget(root, 5);
    cout << ans;
    return 0;
}