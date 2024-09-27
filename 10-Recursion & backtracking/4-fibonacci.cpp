#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{
	if(n==0 || n==1){
		return n;}
	int a =0; int b=1; int c ;
	cout<<a <<" "<<b ;
	for(int i =2; i<=n; i++)
	{
		c= a+b;
		cout<<" "<<c;
		a =b;
		b =c;
	}
	return c ;
}


int main()
{
	int n ;
	cin>>n;
	cout<<"Enter the number for what you want to print the fibonacci series "<<endl;
	int ans = fibonacci(n);
	cout<<endl<<"the final term " << ans << endl;
	return 0;
	
}