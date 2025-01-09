// leetcode.com/problems/diameter-of-binary-tree/description/
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructor while crearting node left and rigth node will be null
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "enter the value for node " << endl;
    int val;
    cin >> val;

    if (val == -1)
        return NULL;
    else
    {
        // valid value
        Node *root = new Node(val);
        cout << "adding left chilf for tree " << endl;
        root->left = createTree();
        cout << "adding right child node" << endl;
        root->right = createTree();

        return root;
    }
}

/**
 *-----------------------------------------SECOND SOLUTION WILL TAKE O(N)TIME-------------------

int height(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = height(root->left, ans);
    int right = height(root->right, ans);
    ans = max(ans, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    height(root, ans);
    return ans;
}
 */

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int ansleft = maxDepth(root->left);
    int ansright = maxDepth(root->right);
    return 1 + max(ansleft, ansright);
}

int diameterOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;

    int option1 = diameterOfBinaryTree(root->left);             // may be left k kisi nodde ki diamtere jyada hogi
    int option2 = diameterOfBinaryTree(root->right);            //// may be right k kisi nodde ki diamtere jyada hogi
    int option3 = maxDepth(root->left) + maxDepth(root->right); // jis node pe hain waha se right+ left sbse badi diameter hogi

    return max(max(option1, option2), option3);
}

int main()
{
    Node *root = createTree();
    cout << diameterOfBinaryTree(root);
    return 0;
}