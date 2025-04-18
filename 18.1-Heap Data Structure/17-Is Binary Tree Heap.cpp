// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool checkComplete(struct Node *root)
{
    if (root == NULL)
        return true;

    queue<struct Node *> que;
    que.push(root);
    bool ans = false;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            struct Node *frontNode = que.front();
            que.pop();

            if (frontNode == NULL)
                ans = true;
            else
            {
                if (ans == true)
                    return false;

                que.push(frontNode->left);
                que.push(frontNode->right);
            }
        }
    }

    return ans = true;
    ;
}

// check for maxHeap
bool checkMaxHeap(struct Node *root)
{
    if (root == NULL)
        return true;

    queue<struct Node *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            struct Node *frontNode = que.front();
            que.pop();

            if (frontNode->left != NULL)
            {
                if (frontNode->data < frontNode->left->data)
                    return false;
                que.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                if (frontNode->data < frontNode->right->data)
                    return false;
                que.push(frontNode->right);
            }
        }
    }
    return true;
}

bool isHeap(struct Node *tree)
{
    bool ans1 = checkComplete(tree);
    bool ans2 = checkMaxHeap(tree);
    return ans1 && ans2;
}

int main()
{
    struct Node *a = new Node(1);
    bool ans = isHeap(a);
    return 0;
}