#include<bits/stdc++.h>

using namespace std;

bool solve (string str  , int i , int j)
{
    if(i>=j)
        return true ;
    
    if(str[i]!=str[j])
        return false ;

    bool ans = solve(str , i+1 , j-1);
    return ans ;
}


int main()
{

    string str;
    cout<<"Enter the String that you want to check weather palindrome or not ";
    cin>>str;
    int i =0; int j = str.length()-1;
    bool ans = solve(str , i , j);
    if(ans)
        cout<<"The Givenn string is Palindrome"<<endl;
    else
        cout<<"The Given string is not Palindrome "<<endl;
    return 0;
}