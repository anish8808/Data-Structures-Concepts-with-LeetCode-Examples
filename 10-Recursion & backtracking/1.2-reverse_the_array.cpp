#include <bits/stdc++.h>

using namespace std ;

void printArray(vector<int>arr , int n , int i)
{
	if(i>=n)
		return;
	printArray(arr , n , i+1);
	cout<<arr[i]<< " ";
}

int main()
{
	int n ;
	cout<<"Enter the size of the Array = "<<endl;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	printArray(arr , n , 0);
	return 0;
}