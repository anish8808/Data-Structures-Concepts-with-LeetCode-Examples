
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

void solveDFS(TreeNode *root, int &targetSum, long long sum, int &ans)
{
    if (root == NULL)
        return;

    sum = root->val + sum;
    if (sum == targetSum)
        ans++;

    solveDFS(root->left, targetSum, sum, ans);
    solveDFS(root->right, targetSum, sum, ans);
}
void solve(TreeNode *root, int &targetSum, int &ans)
{
    if (root == NULL)
        return;

    long long sum = 0;
    solveDFS(root, targetSum, sum, ans);
    solve(root->left, targetSum, ans);
    solve(root->right, targetSum, ans);
}

int pathSum(TreeNode *root, int targetSum)
{
    int ans = 0;
    solve(root, targetSum, ans);
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    int ans = pathSum(root, 30);
    cout << ans << endl;
    return 0;
}