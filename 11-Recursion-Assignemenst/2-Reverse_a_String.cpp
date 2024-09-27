#include<bits/stdc++.h>
using namespace std;

void Reverse(string &str , int i , int j)
{
    if(i>=j)
        return ;

    swap(str[i] , str[j]);
    Reverse(str , i+1 , j-1);
}

int main()
{

    string str ;
    cout<<"Enter the string that you want to reverse ";
    cin>>str;
    int i =0 ; int j = str.length()-1;
    Reverse(str , i , j);
    cout<<"The given string has been reversed "<<str<<endl;
    return 0;
}