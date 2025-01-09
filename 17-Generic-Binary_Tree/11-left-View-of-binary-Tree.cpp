// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

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
    solve(root->left, ans, lvl);
    solve(root->right, ans, lvl);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    int lvl = 0;
    solve(root, ans, lvl);
    return ans;
}

int main()
{
    Node *root = createTree();
    vector<int> ans = leftView(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}

// IDEA1 - idea to solve this problem is simple take the empty array and start with root node
//  check if level and size of the vector is same that means at that level we have not added any element so store it the vector array