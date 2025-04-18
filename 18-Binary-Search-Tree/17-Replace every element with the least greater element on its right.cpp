// https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/0
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void createBST(TreeNode *&root, int input, int &greaterElemnet)
{
    if (root == NULL)
    {
        root = new TreeNode(input);
        return;
    }
    if (root->val > input)
    {
        greaterElemnet = root->val;
        createBST(root->left, input, greaterElemnet);
    }
    else
    {
        createBST(root->right, input, greaterElemnet);
    }
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    TreeNode *root = 0;
    int greaterElemnet = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        createBST(root, arr[i], greaterElemnet);
        arr[i] = greaterElemnet;
        greaterElemnet = -1;
    }

    return arr;
}

int main()
{
    vector<int> ans{1, 2, 3, 4, 5};
    vector<int> res = findLeastGreater(ans, 5);

    for (auto i : res)
        cout << i << endl;
    return 0;
}