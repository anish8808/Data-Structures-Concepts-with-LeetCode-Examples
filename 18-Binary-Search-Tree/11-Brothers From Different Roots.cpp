// https://leetcode.com/problems/validate-binary-search-tree/description/

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

// returns the inorder successor of the Node x in BST (rooted at 'root')
bool checkPresent(int key, TreeNode *root2)
{
    if (root2 == NULL)
        return false;

    bool leftans = false;
    bool rightans = false;
    if (root2->val == key)
        return true;
    else if (root2->val > key)
        leftans = checkPresent(key, root2->left);
    else
        rightans = checkPresent(key, root2->right);

    return leftans || rightans;
}

void solve(TreeNode *root1, TreeNode *root2, int x, int &ans)
{
    if (root1 == NULL)
        return;

    if (checkPresent(x - root1->val, root2))
        ans++;

    solve(root1->left, root2, x, ans);
    solve(root1->right, root2, x, ans);
}
int countPairs(TreeNode *root1, TreeNode *root2, int x)
{
    int ans = 0;
    solve(root1, root2, x, ans);
    return ans;
}

int main()
{
    // creating BST1
    cout << "Creating BST1" << endl;
    TreeNode *root1 = createTree();
    cout << "Creating BST2" << endl;
    TreeNode *root2 = createTree();
    int x = 11;
    int ans = countPairs(root1, root2, x);
    return 0;
}