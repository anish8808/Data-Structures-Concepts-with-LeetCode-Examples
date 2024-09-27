#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
	vector<int> arr(n+1);
	arr[0]=1;
	arr[1]=1;
	for(int i=2; i<=n; i++)
		arr[i]=arr[i-1]+arr[i-2];
	return arr[n];
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