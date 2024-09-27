#include <bits/stdc++.h>

using namespace std;

void checkascendigOrder(int arr[] , int i , int n , bool & check)
{
	if(i>=(n-1))
		return;
	
	if(arr[i]>arr[i+1])	
	{
		check = false ;
		return ;
	}
	
	checkascendigOrder(arr , i+1 , n , check);
}

int main()
{
	int arr[5]={10 , 11, 12 , 12 ,13};
	int i =0; 
	bool check = true ;
	checkascendigOrder(arr , i , 1, check);
	if(check)
		cout<<"Array is an ascending order";
	else
		cout<<"Array is not in ascending order";
	return 0;
}