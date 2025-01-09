// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/0

// https://www.geeksforgeeks.org/bottom-view-binary-tree/
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
void solve(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    solve(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    solve(root->left, head);
}

Node *bToDLL(Node *root)
{
    Node *head = NULL;
    solve(root, head);

    return head;
}

int main()
{
    Node *root = createTree();
    root = bToDLL(root);
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    return 0;
}