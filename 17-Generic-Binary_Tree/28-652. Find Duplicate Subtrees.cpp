
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

string preorder(TreeNode *root, unordered_map<string, int> &mapp, vector<TreeNode *> &ans)
{
    if (root == NULL)
        return "N";

    string unique_str = to_string(root->val) + "," + preorder(root->left, mapp, ans) + "," + preorder(root->right, mapp, ans);

    if (mapp[unique_str] == 1)
    {
        ans.push_back(root);
    }

    mapp[unique_str]++;

    return unique_str;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root, unordered_map<string, int> &mapp, vector<TreeNode *> &ans)
{
    preorder(root, mapp, ans);
    return ans;
}

int main()
{
    vector<TreeNode *> ans;
    unordered_map<string, int> mapp;
    TreeNode *root = createTree();
    vector<TreeNode *> res = findDuplicateSubtrees(root, mapp, ans);
    for (auto i : res)
        cout << i->val;
    return 0;
}
