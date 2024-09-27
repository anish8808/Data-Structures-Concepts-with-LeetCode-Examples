#include<bits/stdc++.h>

using namespace std;


class Node {
    public:
        int data;
        Node * next;
    
    //constructor

    Node(int value)
    {
        this->data = value ;
        this->next = NULL;
    }
};

int getLength(Node* &head)
{
    Node * temp = head ;
    int len =0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void PrintLL(Node* head)
{
    Node* temp = head ;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node * insartAtHead(int value , Node* &head , Node* &tail)
{
    //if the Linked List is empty 
    if(head==NULL && tail ==NULL)
    {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    }
    else{
//LL is not empty 
// node add begin to head node and point as a head 
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    }

    return head;
}

Node* insertAtTail(int value , Node* &head  ,  Node* &tail)
{
    //if LL is impty 
    if(head ==NULL && tail ==NULL)
    {
        Node * newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        Node * newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;  
    }
    return head ;
}


void insertAtValidPos(int value , Node* &head , Node* tail , int pos )
{
    //insert at first Pos then we will resue atthehead fun
    int len = getLength(head);
    if(pos==1)
    {
        insartAtHead(value , head , tail);
    }
    else if(pos == len+1)
    {
        insertAtTail(value ,head , tail);
    }
    else{
        Node* newNode = new Node(value);
        Node* temp = head;
        //position minus-2 steps chlana hoga kyuki specific pos se thoda picche one node rahega 
        pos = pos -2;
        while(pos--)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int findtarget(Node* &head , int target)
{
    Node* temp = head ;
    int i =1;
    while(temp!= NULL)
    {
        if(target==temp->data)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}

void deleteNode(Node* head , Node* tail , int pos)
{
    //if linkedlist is empty
    if(head ==NULL && tail == NULL)
    {
            cout<<"NO need to delete ";
            return ;
    }
    else if (head == tail)
    {
        //Single node ho toh 
        Node * temp = head ;
        head = NULL;
        tail = NULL;
        //kyuki maine node banate time humne heap memory use ki h toh delete se memory delete karni padegi kyuki new keyword use kiya h humne
        delete temp;
    }
    else{
        //multipile node h 
        Node * temp = head ;
        if(pos ==1)
        {
            head = temp->next;
            delete temp;
        }
        else
        {
            pos = pos-2;
            while(pos--)
            {
                temp = temp->next;
            }
            Node* NodetoDelete = temp->next;
            temp->next = temp->next->next;
            delete NodetoDelete;
        }
    }

}

int main()
{
    //stack memory 
        // --> Node first ;

    //Heap Memory

    //--> Node *first = new Node() 

    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);

    // first->next = second;
    // second->next = third;

//AT start head and tail will be at null
    Node* head = NULL;
    Node* tail = NULL;


//INSERT AT HEAD 
    head = insartAtHead(10 , head , tail);
    PrintLL(head);
    head = insartAtHead(20 ,head , tail );
    PrintLL(head);
    head = insartAtHead(30 , head , tail);
    PrintLL(head);

//INSERT AT TAIL
    head = insertAtTail(101 , head , tail);
    PrintLL(head);
    head = insertAtTail(102 , head , tail);
    PrintLL(head);
    head = insertAtTail(103 , head , tail);
    PrintLL(head);

//INSERT AT POSITION

    int len = getLength(head);
    cout<<"Len of the list is" << len<<endl;

    //insert at 1 
    insertAtValidPos(400 , head , tail , 1);
    PrintLL(head);

    //insert at 8
    insertAtValidPos(57, head , tail , 8);
    PrintLL(head);

    //insert at given pos 7
    insertAtValidPos(40, head , tail , 7);
    PrintLL(head);
    
    //insert at any pos
    insertAtValidPos(80, head , tail , 4);
    PrintLL(head);

    //search an target is linkedlist and return the exact pos
    int target = 103;
    int ans = findtarget(head , target);
    if(ans)
        cout<<"given Target is found "<<ans<<endl;
    else    
        cout<<"Target not found"<<endl;

    //

    return 0;
}