
// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
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

vector<int> diagonal(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *frontNode = que.front();
        que.pop();
        while (frontNode != NULL)
        {
            ans.push_back(frontNode->val);

            if (frontNode->left != NULL)
                que.push(frontNode->left);

            frontNode = frontNode->right;
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    vector<int> ans = diagonal(root);
    return 0;
}