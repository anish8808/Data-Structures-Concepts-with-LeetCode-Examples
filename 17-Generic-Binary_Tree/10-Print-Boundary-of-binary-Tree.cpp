// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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

void printLeftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    ans.push_back(root->data);
    if (root->left != NULL)
        printLeftBoundary(root->left, ans);
    else
        printLeftBoundary(root->right, ans);
}

void printLeafNodeBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {

        ans.push_back(root->data);
        return;
    }
    printLeafNodeBoundary(root->left, ans);
    printLeafNodeBoundary(root->right, ans);
}

void printReverseRightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right != NULL)
        printReverseRightBoundary(root->right, ans);
    else
        printReverseRightBoundary(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root)
{
    // code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    printLeftBoundary(root->left, ans);
    printLeafNodeBoundary(root->left, ans);
    printLeafNodeBoundary(root->right, ans);
    printReverseRightBoundary(root->right, ans);

    return ans;
}

int main()
{
    Node *root = createTree();
    vector<int> ans = boundaryTraversal(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}