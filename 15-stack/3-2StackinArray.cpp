#include<bits/stdc++.h>

using namespace std ;

class Stack{
    public:
        int * arr;
        int size;
        int top1;
        int top2;


        Stack(int capacity)
        {
            arr = new int[capacity];
            size = capacity;
            top1 = -1;
            top2 = size;
        }

        void push1(int val){
            if(top2-top1 ==1)
            {
                cout<<"Stack is full"<<endl;
            }
            else{
                top1++;
                arr[top1] = val;
            }
        }

        void push2(int val){
            if(top2-top1==1)
            {
                cout<<"Stack overflow"<<endl;
            }
            else
            {
                top2--;
                arr[top2]=val;
            }
        }

        void pop1(){
            if(top1==-1){
                cout<<"stack1 is underflow"<<endl;
            }
            else   
                {
                    arr[top1]= -1;
                    top1--;
                }
        }

        void pop2(){
            if(top2==size)
            {
                cout<<"Stack2 is underflow"<<endl;
            }
            else
            {
                arr[top2] = -1;
                top2++;
            }
        }

        void print()
        {
            cout<< "top1 :" <<top1<<endl;
            cout<<"top2 :"<<top2<<endl;

            for(int i =0; i<size; i++)
                cout<<arr[i]<<endl;
        }
};


int main()
{
    Stack s(5);
    s.push1(1);
    s.push2(2);
    s.push1(3);
    s.push2(4);
    s.push1(10);
    s.pop1();
    s.push2(23);
    s.print();

    return 0;
}