#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}
// insert element in linkedList at head postion

Node *insertAtHead(int val, Node *head)
{
    // if there is no node in the list
    if (head == NULL)
    {
        Node *temp = new Node(val);
        return temp;
    }
    else
    {
        Node *temp = new Node(val);

        temp->next = head;
        head = temp;
        return head;
    }
}
// insert an element in given PoslinkedList
// insert an element in the linkedlist at the last podtion

int main()
{
    Node *head = NULL;
    head = insertAtHead(5, head);
    head = insertAtHead(4, head);
    head = insertAtHead(3, head);
    head = insertAtHead(2, head);
    head = insertAtHead(1, head);
    PrintList(head);

    return 0;
}