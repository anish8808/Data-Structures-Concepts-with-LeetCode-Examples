// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/0
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

void inorder(TreeNode *root, vector<TreeNode *> &ans)
{

    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root);
    inorder(root->right, ans);
}
TreeNode *flattenBST(TreeNode *root)
{
    vector<TreeNode *> ans;
    inorder(root, ans);

    for (int i = 0; i < ans.size() - 1; i++)
    {
        ans[i]->left = NULL;
        ans[i]->right = ans[i + 1];
    }
    ans[ans.size() - 1]->right = NULL;
    ans[ans.size() - 1]->left = NULL;
    return ans[0];
}

int main()
{
    TreeNode *root = createTree();
    TreeNode *ans = flattenBST(root);
    // cout << ans << endl;
    return 0;
}