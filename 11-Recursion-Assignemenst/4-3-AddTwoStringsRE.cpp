#include<bits/stdc++.h>

using namespace std;

void solve (string str1 , string str2 , string &str3 , int i , int j , int &carry)
{
    if(i<0 && j <0 && carry ==0)
        return ;

    int sum = carry;
    if(i>=0)
    {
        sum += str1[i]-'0';
    }
    if(j>=0)
    {
        sum += str2[j]-'0';
    }
    carry = sum /10;
    sum = sum%10;
    solve(str1 , str2 , str3 , i-1 , j-1 , carry);
    str3.push_back(sum+'0');
}

int main()
{
    string str1 , str2;
    cout<<"Enter the strings ";
    cin>>str1>>str2;
    int i = str1.length()-1;
    int j = str2.length()-1;
    string str3 = "";
    int carry =0;
    solve(str1 , str2 , str3 , i , j , carry);
    cout<<"after Adding the string we got this output"<< str3 <<endl;
    return 0;
}