#include<bits/stdc++.h>

using namespace std;

void findlastOccurenece(string str  , char val , long unsigned int i , int &ans)
{
    if(i>=str.length())
    {
        return ;
    }
    if(val == str[i])
        ans = i;
    
    findlastOccurenece(str , val , i+1 , ans);
}

int main()
{
    string str;
    cout<<"Enter the string ";
    cin>>str;
    char val = 'd';
    int ans = 0;
    findlastOccurenece(str , val  , 0 , ans);
    cout<<"the last occurenece of the char "<<val <<" is "<<ans<<endl;
    return 0;
}