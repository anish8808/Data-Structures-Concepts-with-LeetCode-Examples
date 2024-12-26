// leetcode.com/problems/balanced-binary-tree/
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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int ansleft = height(root->left);
    int ansright = height(root->right);
    return 1 + max(ansleft, ansright);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    bool leftsubtree = isBalanced(root->left);
    bool rightsubtree = isBalanced(root->right);
    bool hieghtdiff = abs(height(root->left) - height(root->right)) <= 1 ? true : false;
    return (leftsubtree && rightsubtree) && hieghtdiff;
}

int main()
{
    Node *root = createTree();
    cout << isBalanced(root); // 3,9,-1 ,-1 ,20,15,-1,-1,7,-1,-1
    return 0;
}