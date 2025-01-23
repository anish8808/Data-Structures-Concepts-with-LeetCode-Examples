
// https://leetcode.com/problems/path-sum-iii/description/
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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // 1st- STEP --> finding the predecescor --> means we have to go left and the right till leaf node this will be the inorder predecesor for curr node

            TreeNode *pred = curr->left;
            while (pred->right != curr && pred->right != NULL)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    vector<int> ans = inorderTraversal(root);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}