// https://leetcode.com/problems/path-sum-ii/description/// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
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

bool solve(Node *root, int targetSum)
{
    if (root == NULL)
        return false;

    // Subtract current node's value from targetSum
    targetSum -= root->data;

    // If we reach a leaf node, check if targetSum is 0
    if (root->left == NULL && root->right == NULL)
    {
        return targetSum == 0;
    }

    // Recursively check left and right subtrees
    bool leftans = solve(root->left, targetSum);
    bool rightans = solve(root->right, targetSum);

    return leftans || rightans;
}
bool hasPathSum(Node *root, int targetSum)
{
    if (root == NULL)
        return false;
    bool ans = solve(root, targetSum);
    return ans;
}
int main()
{
    Node *root = createTree();
    bool ans = hasPathSum(root, 20); // 3,9,-1 ,-1 ,20,15,-1,-1,7,-1,-1
    cout << "The Lowest common ancestor of the given nodes of q and q is = " << ans << endl;
    return 0;
}