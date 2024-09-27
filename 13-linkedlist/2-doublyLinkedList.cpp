#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getLength(Node *&head)
{
    Node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        pos++;
        temp = temp->next;
    }

    return pos;
}

void PrintLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data ;
        temp = temp->next;
        cout <<"-->";
    }
    cout<<"NULL"<<endl;
}

bool searchTarget(Node* &head , int target)
{
    Node* temp = head;
    if(temp==NULL)
    {
        return false;
    }
    
    while(temp!=NULL)
    {
        if(temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}

void insertAthead(int value, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(int value, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPos(int value, Node *&head, Node *&tail, int pos)
{
    int len = getLength(head);

    if (pos == 1)
    {
        insertAthead(value, head, tail);
    }
    else if (pos == (len + 1))
    {
        insertAtTail(value, head, tail);
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        Node *farward = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = farward;
        farward->prev = newNode;
    }
}

void deleteNode(int pos , Node* &head , Node* tail )
{
    if(head==NULL && tail==NULL)
    {
        return;
    }
    else if (head == tail)
    {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else
    {
        int len = getLength(head);
         // if head node delete
         if(pos==1)
         {
            Node* temp = head ;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
         }
         else if(pos == len)
         {
            Node* temp = tail ;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev=NULL;
            delete temp;
         }
         else
         {
            Node * temp = head ;
            for(int i =0; i<pos-2; i++)
            {
                temp= temp->next;
            }
            Node* curr = temp->next;
            Node* farw = curr->next;
            temp->next= farw;
            farw->prev = temp;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
         }
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAthead(1 , head , tail);
    insertAthead(2 , head , tail);
    insertAthead(3 , head , tail);
    PrintLL(head);
    insertAtTail(10, head, tail);
    insertAtTail(20, head, tail);
    insertAtTail(30, head, tail);
    PrintLL(head);
    insertAtPos(60, head, tail, 2);
    PrintLL(head);
    insertAtPos(70, head, tail, 5);
    PrintLL(head);
    insertAtPos(5, head, tail, 1);
    PrintLL(head);
    bool ans = searchTarget(head , 55);
    if(ans)
    {
        cout<<"The target is present is the ll"<<endl;
    }
    else
    {
        cout<<"The target is not present is the ll"<<endl;
    }

    deleteNode(1, head , tail);
    PrintLL(head);
    deleteNode(3, head , tail);
    PrintLL(head);
    deleteNode(7, head , tail);
    PrintLL(head);
    
    return 0;
}