// leetcode.com/problems/maximum-width-of-binary-tree/description/

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
int widthOfBinaryTree(TreeNode *root)
{
    unsigned long long maxWidth = 0;
    if (root == NULL)
        return maxWidth;
    queue<pair<TreeNode *, int>> que;
    que.push(make_pair(root, 1));
    while (!que.empty())
    {
        unsigned long long size = que.size();
        unsigned long long leftmostDept = que.front().second;
        unsigned long long rightmostDept = que.back().second;
        maxWidth = max(maxWidth, rightmostDept - leftmostDept + 1);

        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = que.front().first;
            unsigned long long val = que.front().second;

            if (frontNode->left != NULL)
            {
                que.push(make_pair(frontNode->left, val * 2));
            }
            if (frontNode->right != NULL)
            {
                que.push(make_pair(frontNode->right, val * 2 + 1));
            }
            que.pop();
        }
    }

    return maxWidth;
}
int main()
{
    TreeNode *root = createTree();
    int ans = widthOfBinaryTree(root);
    cout << ans << " ";
    return 0;
}