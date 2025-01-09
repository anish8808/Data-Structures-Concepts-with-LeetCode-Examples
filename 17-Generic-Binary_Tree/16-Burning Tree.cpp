// https://www.geeksforgeeks.org/problems/burning-tree/1// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/0

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
void paraentChildMap(Node *root, unordered_map<Node *, Node *> &RelationMap, Node *&targetNode, int target)
{
    if (root == NULL)
        return;

    if (targetNode == NULL)
    {
        if (root->data == target)
            targetNode = root;
    }

    if (root->left != NULL)
        RelationMap[root->left] = root;

    if (root->right != NULL)
        RelationMap[root->right] = root;

    paraentChildMap(root->left, RelationMap, targetNode, target);

    paraentChildMap(root->right, RelationMap, targetNode, target);
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> RelationMap;
    int time = 0;
    if (root == NULL)
        return time;

    // created the child paraents mapping
    Node *targetNode = NULL;
    paraentChildMap(root, RelationMap, targetNode, target);
    if (targetNode == NULL)
        return time;
    unordered_map<Node *, bool> visited;
    queue<Node *> que;
    bool check = false;
    que.push(targetNode);
    visited[targetNode] = true;
    while (!que.empty())
    {
        check = false;
        int size = que.size();

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = que.front();
            que.pop();
            // left condition
            if (frontNode->left != NULL && !visited[frontNode->left])
            {
                que.push(frontNode->left);
                visited[frontNode->left] = true;
                check = true;
            }
            // right condition
            if (frontNode->right != NULL && !visited[frontNode->right])
            {
                que.push(frontNode->right);
                visited[frontNode->right] = true;
                check = true;
            }
            // parenets condition
            if (RelationMap.count(frontNode) && !(visited[RelationMap[frontNode]]))
            {
                que.push(RelationMap[frontNode]);
                visited[RelationMap[frontNode]] = true;
                check = true;
            }
        }

        if (check)
            time++;
    }

    return time;
}

int main()
{
    Node *root = createTree();
    int min = minTime(root, 8);
    cout << "minimum time taken to burn the tree" << min << endl;
    return 0;
}