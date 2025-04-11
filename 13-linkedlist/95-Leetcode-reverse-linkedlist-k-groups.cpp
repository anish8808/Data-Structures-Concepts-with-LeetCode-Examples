#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    // constructor

    ListNode(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

pair<ListNode *, ListNode *> reverseList(ListNode *start, ListNode *end)
{
    ListNode *prev = nullptr;
    ListNode *curr = start;
    ListNode *nxt = nullptr;
    ListNode *stop = (end) ? end->next : nullptr;
    while (curr != stop)
    { // Reverse till end (inclusive)
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return {prev, start}; // New head of the reversed group
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevTail = NULL;
    ListNode *newHead = NULL;

    while (temp != NULL)
    {
        ListNode *start = temp;
        ListNode *end = temp;
        int range = 1;
        while (range < k && end != NULL)
        {
            end = end->next;
            range++;
        }

        if (end == NULL)
            break;

        temp = end->next;
        auto [newlyHead, newTail] = reverseList(start, end);

        if (newHead == NULL)
        {
            newHead = newlyHead;
        }
        if (prevTail != NULL)
        {
            prevTail->next = newlyHead;
        }

        prevTail = newTail;
        prevTail->next = temp;
    }

    if (newHead != NULL)
        return newHead;
    else
        return head;
};

void PrintLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *insartAtHead(int value, ListNode *&head, ListNode *&tail)
{
    // if the Linked List is empty
    if (head == NULL && tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        //  node add begin to head node and point as a head
        ListNode *newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    return head;
}
int main()
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    head = insartAtHead(10, head, tail);

    head = insartAtHead(20, head, tail);

    head = insartAtHead(30, head, tail);

    // INSERT AT TAIL
    head = insartAtHead(101, head, tail);

    head = insartAtHead(102, head, tail);

    head = insartAtHead(103, head, tail);
    PrintLL(head);

    ListNode *headnew = reverseKGroup(head, 2);
    PrintLL(headnew);

    return 0;
}