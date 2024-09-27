#include<bits/stdc++.h>

using namespace std ;

class Stack {
    public:
        int* arr;
        int size ;
        int top;

        Stack(int capacity)
        {
            arr = new int[capacity];
            top = -1;
            size = capacity;
        }


        void push(int val)
        {
            if(top==size-1)
            {
                //stack is already full;
                cout<<"Stack `Overflow"<<endl;
            }
            else{
                top++;
                arr[top] = val;
            }
        }
        void pop()
        {
            if(top ==-1)
            {
                cout<<"Stack is UnderFlow"<<endl;
            }
            else{
                arr[top] = -1;
                top--;
            }

        }
        int  getSize()
        {
            return top+1;
        }
        bool isEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }

        int getTop()
        {
            if(top==-1)
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else
            {
                return arr[top];
            }
        }

        void print()
        {
            for(int i =0; i<size; i++)
            {
                cout<<arr[i]<<endl;
            }
        }
};

int main()
{
// input we will have the size of the stack

//initial top will be -1 because no element is there

//creation stack 
Stack s(5);
//s.print();

s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);

//overflow
s.push(60);
s.print();

cout<<s.getTop()<<endl;
cout<<s.getSize()<<endl;
cout<<s.isEmpty()<<endl;

s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.print();



return 0;

}