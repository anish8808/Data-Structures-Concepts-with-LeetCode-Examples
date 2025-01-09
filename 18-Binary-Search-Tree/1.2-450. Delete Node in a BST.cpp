// https://leetcode.com/problems/delete-node-in-a-bst/

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

int getMax(TreeNode *root)
{
    if (root == NULL)
        return -1;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->val;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->val == key)
    {
        // here we will have 4 case
        // 1st case ki leaf node hain
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 2nd case root ka left exist kar raha hain right nahi

        if (root->left != NULL && root->right == NULL)
        {
            TreeNode *leftchild = root->left;
            root->left = NULL;
            delete root;
            return leftchild;
        }

        // 3rd case root ka right exist kar raha hain left nahi

        if (root->left == NULL && root->right != NULL)
        {
            TreeNode *rightchild = root->right;
            root->right = NULL;
            delete root;
            return rightchild;
        }

        // Agar root ka left aur right dono exist karta hain toh

        if (root->left != NULL && root->right != NULL)
        {
            // hum root se just chhota element lenge jo root ke left ke right wala extrem hoga
            int maxVal = getMax(root->left);
            root->val = maxVal;
            // now call the same function to delte the maxVal;

            root->left = deleteNode(root->left, maxVal);

            return root;
        }
    }
    else
    {
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
    }

    return root;
}

int main()
{
    TreeNode *root = createTree();
    root = deleteNode(root, 5);
    return 0;
}