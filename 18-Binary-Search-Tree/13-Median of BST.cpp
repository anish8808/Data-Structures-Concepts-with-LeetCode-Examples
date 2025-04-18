// https://www.geeksforgeeks.org/problems/median-of-bst/1
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

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, ans);

    ans.push_back(root->val);

    inorder(root->right, ans);
}
float findMedian(TreeNode *root)
{
    // Code here
    vector<int> ans;
    inorder(root, ans);
    int size = ans.size();
    if (size % 2 == 0)
    {
        float final = float(ans[size / 2] + ans[(size / 2) - 1]) / 2;
        return final;
    }
    else
    {
        return float(ans[size / 2]);
    }
}

// another approached using morris traversal

int MorriesCountNode(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            count++;
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = curr->left;
            while (pred->right != curr && pred->right)
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
                count++;
                curr = curr->right;
            }
        }
    }

    return count;
}

float MorriesMidean(TreeNode *root, int n)
{
    int odval1 = n / 2;
    int even1 = (n / 2) - 1;
    int median1 = 0;
    int median2 = 0;

    if (root == NULL)
        return 0;

    int count = 0;
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            if (odval1 == count)
                median1 = curr->val;
            if (even1 == count)
                median2 = curr->val;
            count++;
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = curr->left;
            while (pred->right != curr && pred->right)
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
                if (odval1 == count)
                    median1 = curr->val;
                if (even1 == count)
                    median2 = curr->val;
                count++;
                curr = curr->right;
            }
        }
    }

    return (n % 2 == 0) ? (median1 + median2) / 2.0 : median1;
}

float findMedian2(TreeNode *root)
{
    int n = MorriesCountNode(root);
    float ans = MorriesMidean(root, n);
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    float ans = findMedian(root);
    cout << ans << endl;
    return 0;
}