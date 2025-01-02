// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
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

void solve(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;

    if (lvl == ans.size())
        ans.push_back(root->data);
    lvl++;
    solve(root->right, ans, lvl);
    solve(root->left, ans, lvl);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    int lvl = 0;
    solve(root, ans, lvl);
    return ans;
}

int main()
{
    Node *root = createTree();
    vector<int> ans = rightView(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}