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
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
            q.pop();
        }
        cout << endl;
    }
}
int main()
{
    Node *root;
    root = createTree();
    levelOrderTraversal(root);

    return 0;
}