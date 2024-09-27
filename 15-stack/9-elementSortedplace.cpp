#include<bits/stdc++.h>

using namespace std ;

void findpos(stack<int> & s , int val )
{
    if(s.empty())
    {
        s.push(val);
        return ;
    }

    if(!s.empty() && s.top()<val)
    {
        s.push(val);
        return ;
    }
    
    int top = s.top();
    s.pop();
    findpos(s , val);
    s.push(top);
}
int main()
{
    stack<int>s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    int val = 23;
    findpos(s1 , val);
    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }


    return 0;
}