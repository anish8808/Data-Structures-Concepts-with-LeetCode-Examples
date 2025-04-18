#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

ListNode *revesre(ListNode *head, int &count, int right)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt = NULL;
    while (count <= right)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    head->next = curr;

    return prev;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || left == right)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy;
    int count = 1;
    while (count < left)
    {
        temp = temp->next;
        count++;
    }

    temp->next = revesre(temp->next, count, right);
    head = dummy->next;
    delete (dummy);
    return head;
}