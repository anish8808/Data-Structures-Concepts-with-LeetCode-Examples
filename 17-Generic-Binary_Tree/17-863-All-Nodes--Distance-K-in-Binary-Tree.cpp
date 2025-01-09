// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    // constructor while crearting node left and rigth node will be null
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *createTree()
{
    cout << "enter the value for node " << endl;
    int val;
    cin >> val;

    if (val == -1)
        return NULL;
    else
    {
        // valid value
        TreeNode *root = new TreeNode(val);
        cout << "adding left chilf for tree " << endl;
        root->left = createTree();
        cout << "adding right child node" << endl;
        root->right = createTree();

        return root;
    }
}
void childParentsRelation(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &relation)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        relation[root->left] = root;
    if (root->right != NULL)
        relation[root->right] = root;

    childParentsRelation(root->left, relation);
    childParentsRelation(root->right, relation);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    // taking vector array to store te value
    vector<int> ans;

    // if targetNode is null the ans should be null
    if (target == NULL)
        return ans;

    // parenet chinld mapping
    unordered_map<TreeNode *, TreeNode *> relation;
    childParentsRelation(root, relation);

    // visited map to check weather that node already seen or not
    unordered_map<TreeNode *, bool> visited;

    // take a queue and process the BFS algorithm
    queue<TreeNode *> que;
    int distance = 0; // taking distance that will tell the level

    // process the starting node that will be target node here and push to the queus
    que.push(target);
    visited[target] = true;
    while (!que.empty())
    {
        int size = que.size();
        bool nodeSeen = false;
        // Process nodes level by level
        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = que.front();
            que.pop();

            // if the distance equal to k then we will store the node val in ans
            if (distance == k)
                ans.push_back(frontNode->val);

            // left child process in the queue
            if (frontNode->left != NULL && !visited[frontNode->left])
            {
                que.push(frontNode->left);
                visited[frontNode->left] = true;
                nodeSeen = true;
            }

            // right child process in the queue
            if (frontNode->right != NULL && !visited[frontNode->right])
            {
                que.push(frontNode->right);
                visited[frontNode->right] = true;
                nodeSeen = true;
            }

            // parantes node process in the queue
            if (relation.count(frontNode) && !visited[relation[frontNode]])
            {
                que.push(relation[frontNode]);
                visited[relation[frontNode]] = true;
                nodeSeen = true;
            }
        }
        // else we will move forword
        if (nodeSeen == true)
            distance++;
    }
    return ans;
}

int main()
{
    TreeNode *root = createTree();
    TreeNode *q = new TreeNode(12);
    vector<int> ans = distanceK(root, q, 12);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}