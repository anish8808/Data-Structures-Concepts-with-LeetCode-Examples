#include<bits/stdc++.h>


using namespace std ;

void inserAtBottom(stack<int> &s , int value)
{
    if(!s.empty())
    {
        s.push(value);
        return ;
    }

    int val = s.top();
    s.pop();
    inserAtBottom(s , value);
    s.push(val);
}

int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int value = 13;

    inserAtBottom(s , value);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}