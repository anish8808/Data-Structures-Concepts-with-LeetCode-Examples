#include<bits/stdc++.h>

using namespace std;
int solve (stack<int> &s , int count)
{
        if(count==0)
            return s.top();

        int val = s.top();
        s.pop();
        int ans = solve(s , count-1);
        s.push(val);

    return ans;
}

int main()
{

    // find the middle number in Stack 

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    int size = s.size();
    int count = size/2;
    int val = solve(s ,count);
    cout<<val<<endl;

    return 0;
}