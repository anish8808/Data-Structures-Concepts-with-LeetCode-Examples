#include<bits/stdc++.h>

using namespace std ;

bool checkSorted(stack<int> &s , int maxi)
{
    if(s.empty())
        return true;

    if(maxi<s.top())
        return false;
   
    int val = s.top();
    maxi = s.top();
    s.pop();
    bool ans = checkSorted(s , maxi);
    s.push(val);
    return ans;       
}

int main()
{
    stack<int>s1;
    stack<int>s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    int len = s1.size();
    int count = len/2;

    while(count--)
    {
        int top = s1.top();
        s2.push(top);
        s1.pop();
    }
    cout<<"the middile element is "<<s1.top()<<endl;
    while(!s2.empty())
    {
        int top = s2.top();
        s1.push(top);
        s2.pop();
    }

    // while(!s1.empty())
    // {
    //     cout<<s1.top()<<endl;
    //     s1.pop();
    // }
    int maxi = INT_MAX;
    bool ans = checkSorted(s1 ,maxi);
    if(ans)
    {
        cout<<"stack is sorted"<<endl;
    }
    else
    {
        cout<<"stack is not sorted ";
    }
    return 0;
}