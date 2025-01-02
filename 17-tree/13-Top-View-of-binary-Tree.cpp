// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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

vector<int> topView(Node *root)
{
    queue<pair<Node *, int>> que;
    unordered_map<int, Node *> map;
    int minXtream = INT_MAX;
    int maxXtream = INT_MIN;
    que.push(make_pair(root, 0));
    while (!que.empty())
    {
        pair<Node *, int> frontPair;
        frontPair = que.front();
        Node *frontNode = frontPair.first;
        int hd = frontPair.second;
        minXtream = min(minXtream, hd);
        maxXtream = max(maxXtream, hd);
        que.pop();
        if (map.find(hd) == map.end())
            map[hd] = frontNode;

        if (frontNode->left != NULL)
        {
            que.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right != NULL)
        {
            que.push(make_pair(frontNode->right, hd + 1));
        }
    }

    vector<int> ans;
    for (int i = minXtream; i <= maxXtream; i++)
    {
        Node *temp = map[i];
        ans.push_back(temp->data);
    }
    return ans;
}

int main()
{
    Node *root = createTree();
    vector<int> ans = topView(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}