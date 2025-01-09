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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    bool check = true;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> ansEach(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = que.front();
            que.pop();

            // logic to stroe the elements in the vector
            int index = check ? i : size - 1 - i;
            ansEach[index] = frontNode->val;

            if (frontNode->left != NULL)
            {
                que.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                que.push(frontNode->right);
            }
        }
        check = !check;
        ans.push_back(ansEach);
    }

    return ans;
}
int main()
{
    TreeNode *root = createTree();
    vector<vector<int>> ans = zigzagLevelOrder(root);

    return 0;
}