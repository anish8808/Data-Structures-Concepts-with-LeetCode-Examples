// leetcode.com/problems/path-sum-ii/
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

void solve(Node *root, int targetSum, int sum, vector<vector<int>> &ans, vector<int> singleans)
{
    if (root == NULL)
        return;

    sum = sum + root->data;
    singleans.push_back(root->data);
    // if node is leaf node then we need to check the sum and if equal to target_sum then store the whole array
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == targetSum)
            ans.push_back(singleans);

        return;
    }
    solve(root->left, targetSum, sum, ans, singleans);
    solve(root->right, targetSum, sum, ans, singleans);
}
vector<vector<int>> pathSum(Node *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> singleans;
    int sum = 0;
    solve(root, targetSum, sum, ans, singleans);
    return ans;
}
int main()
{
    Node *root = createTree();
    vector<vector<int>> ans = pathSum(root, 22); // 3,9,-1 ,-1 ,20,15,-1,-1,7,-1,-1
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << endl;
    }
    return 0;
}