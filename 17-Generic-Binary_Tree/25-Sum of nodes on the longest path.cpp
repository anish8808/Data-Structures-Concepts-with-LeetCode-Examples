
// www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

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

void solve(TreeNode *root, int &maxans, int sum, int &maxCount, int count)
{
    if (root == NULL)
        return;

    sum = sum + root->val;
    count = count + 1;
    if (count > maxCount)
    {
        maxCount = count;
        maxans = sum;
    }
    else if (count == maxCount)
    {
        maxans = max(maxans, sum);
    }

    solve(root->left, maxans, sum, maxCount, count);
    solve(root->right, maxans, sum, maxCount, count);
}

int sumOfLongRootToLeafPath(TreeNode *root)
{
    // code here
    if (root == NULL)
        return -1;
    int maxans = INT_MIN;
    int sum = 0;
    int maxCount = 0;
    int count = 0;
    solve(root, maxans, sum, maxCount, count);

    return maxans;
}

int main()
{
    TreeNode *root = createTree();
    int ans = sumOfLongRootToLeafPath(root);
    cout << ans << endl;
    return 0;
}
