#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack <char> s;

    string name = "anishwala";

    for(int i =0; i<name.length(); i++)
    {
        char ch = name[i];
        s.push(ch);
    }

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}