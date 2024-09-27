#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

string AddStrings(string str1 , string str2)
{
    int i = str1.length()-1;
    int j = str2.length()-1;
    string str3 = "";
    int carry  =0;
    while(i>=0 || j>=0 )
    {
        int sum = carry;
        if(i>=0) sum += str1[i--]-'0';
        if(j>=0) sum +=str2[j--]-'0';
        carry = sum/10;
        sum = sum%10;
        str3.push_back(sum+'0');
    }
    if(carry!=0)
        str3.push_back(carry+'0');

    reverse(str3.begin() , str3.end());
    
    return str3;
}

int main()
{
    string str1 , str2;
    cout<<"Enter the strings that you want to append ";
    cin>>str1>>str2;
    string str3 =AddStrings(str1 , str2 );
    cout<<"the final string after adding the above string will be " <<str3 ;
    return 0;
}