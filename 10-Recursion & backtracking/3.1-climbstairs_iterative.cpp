#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
	if(n==0 || n==1)
		return 1;
	int a =1; int b =1; int c;
	for(int i=2; i<=n; i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main()
{
	int n ;
	cout<< "the total number of stairs = " ;
	cin>>n;
	int ans = climbStairs(n);
	cout<<endl<<"the total no of ways to reach the top is = "<< ans <<endl;
	
	return 0;
}