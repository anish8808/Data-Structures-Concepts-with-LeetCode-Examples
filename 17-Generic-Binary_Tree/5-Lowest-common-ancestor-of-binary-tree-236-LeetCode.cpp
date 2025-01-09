// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;
    if (root->data == p->data)
        return p;
    if (root->data == q->data)
        return q;

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL && right == NULL)
        return NULL;
    else if (left != NULL && right == NULL)
        return left;
    else if (left == NULL && right != NULL)
        return right;
    else
        return root;
}

int main()
{
    Node *root = createTree();
    Node *p, *q;
    p->data = 5;
    p->right = NULL, p->left = NULL;
    q->data = 1;
    q->right = NULL, q->left = NULL;
    Node *ans = lowestCommonAncestor(root, p, q); // 3,9,-1 ,-1 ,20,15,-1,-1,7,-1,-1
    cout << "The Lowest common ancestor of the given nodes of q and q is = " << ans->data << endl;
    return 0;
}