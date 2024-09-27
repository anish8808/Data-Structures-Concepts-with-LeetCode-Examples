#include<bits/stdc++.h>

using namespace std;

void insertAtbottom(stack<int> &s , int val)
{
    if(s.empty()){
        s.push(val);
        return;
    }
    
    int top = s.top();
    s.pop();
    insertAtbottom(s , val);
    s.push(top);
}

void reverseStack(stack<int>&s)
{
    if(s.empty())
        return ;


    int val = s.top();
    s.pop();
    reverseStack(s);
    insertAtbottom(s , val);
}

int main()
{
    stack<int>s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    reverseStack(s1);
    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }

    return 0;
}