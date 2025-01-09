#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void buildBST(Node *&root, int val)
{
    if (root == NULL)
        root = new Node(val);
    else
    {
        if (val < root->data)
        {
            buildBST(root->left, val);
        }
        else
        {
            buildBST(root->right, val);
        }
    }
}
Node *createTree()
{
    cout << "enter the value for node " << endl;
    int val;
    cin >> val;
    Node *root = NULL;
    while (val != -1)
    {
        buildBST(root, val);
        cout << "enter the value for node " << endl;
        cin >> val;
    }

    return root;
}
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}

void printlabelorder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

// get minimum elemenet is the given BST
int getMin(Node *root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

// get the maximum element in the given BST
int getMax(Node *root)
{
    if (root == NULL)
        return -1;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

// search the elemenet in the given BST

bool searchElement(Node *root, int element)
{
    if (root == NULL)
        return false;

    if (root->data == element)
        return true;

    if (root->data > element)
    {
        bool left = searchElement(root->left, element);
        if (left == true)
            return true;
    }
    else
    {
        bool right = searchElement(root->right, element);
        if (right == true)
            return true;
    }

    return false;
}
int main()
{
    Node *root = createTree();
    printlabelorder(root);
    preorder(root);
    inorder(root);
    postorder(root);
    int mini = getMin(root);
    int maxi = getMax(root);
    int element = -1;
    bool ans = searchElement(root, element);
    if (ans)
    {
        cout << "element is present in the tree" << endl;
    }
    else
    {
        cout << "element is not present in the given binary search tree" << endl;
    }

    cout << "the minium element of the BST is " << mini << endl;
    cout << " the maximux element of the BST is " << maxi << endl;
    return 0;
}