#include<bits/stdc++.h>

using namespace std ;


int main()
{

    stack<int>s;

    //insertion

    s.push(10);
    s.push(20);
    s.push(30);

    //size

    cout<<s.size()<<endl;

    //check empty or not 

    cout<<s.empty()<<endl;

    //peek element 
    cout<<s.top()<<endl;

    //removal of the element 
    //we cant access random element;

    s.pop();
    cout<< s.top()<<endl;


    return 0;
}