#include <bits/stdc++.h>

using namespace std;

/*Trees are non-linear data strcture, can be move any direction
Now will see the tree topology
Starting Node is called rootNode
another nodes will call as a child node
also we have some level in the tree
same level nodes called siblings nodes
the node that have no child called leaf Node
 */
/* Binary tree have atmost 2 child either 0 ,1 or 2 child
 parantes up child called ancestor
 syccessor is reverse of ancesstor*/

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

void preOrderTraversal(Node *root)
{
    // node print , then left , then right
    if (root == NULL)
        return;

    cout << root->data << endl;
    // left subtree
    preOrderTraversal(root->left);
    // right subtree
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // phle left , then node print , then right
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << endl;
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    //->phle left , Phir Right , then node print
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << endl;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    // logic
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
            cout << front->data << endl;
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    // lets say create a tree having value
    // tree creation
    // preOrder Traversal
    // inOrder Traversal
    // postOrder Traversal
    // levelOrder Traversal(using Queue)
    // homework-> level order right to left
    // zigzag print
    // height of tree

    Node *root;
    root = createTree();
    preOrderTraversal(root);
    cout << endl;
    inOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}