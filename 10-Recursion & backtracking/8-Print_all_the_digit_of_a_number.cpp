#include<bits/stdc++.h>

using namespace std ;

void printAllDigitofNumber(int n)
{
	if(n==0)
		return ;
	int vall = n%10;
	cout<<vall<<" ";
	printAllDigitofNumber(n/10);
	int val = n%10;
	cout<<val<<" ";
}

int main()
{
	int n = 7465;
	printAllDigitofNumber(n);
	return 0;
}