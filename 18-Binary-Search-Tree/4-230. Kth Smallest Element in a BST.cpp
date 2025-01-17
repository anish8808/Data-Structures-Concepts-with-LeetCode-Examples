// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
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

///---------------------------------------------------->>FIRST SOLUTION WITHOUT RECUSRIONS----------->
// void inOrderBST(TreeNode* root , vector<int>&ans)
// {
//     if(root==NULL)
//         return;

//     inOrderBST(root->left , ans);
//     ans.push_back(root->val);
//     inOrderBST(root->right , ans);
// }
// int kthSmallest(TreeNode* root, int k) {
//     vector<int>nums;
//     inOrderBST(root , nums);
//     if(k<=nums.size())
//     {
//         return nums[k-1];
//     }
//     else
//     {
//         return -1;
//     }
// }

///---------------------------------------------------->>SECOND SOLUTION WITH RECUSRIONS----------->

void solve(TreeNode *root, int k, int &ans, int &index)
{
    if (root == NULL)
        return;

    solve(root->left, k, ans, index);
    index++;
    if (index == k)
    {
        ans = root->val;
        return;
    }
    solve(root->right, k, ans, index);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = -1;
    int index = 0;
    solve(root, k, ans, index);
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    int ans  = kthSmallest(root, 3);
    cout << ans << endl;
    return 0;
}