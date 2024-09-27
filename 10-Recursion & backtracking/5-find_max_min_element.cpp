#include <bits/stdc++.h>

using namespace std;

void Find_maxi(vector<int>&nums, int& n , int i ,  int & max)
{
	if(i>=n)
		return;
	if(nums[i]>max)
		max = nums[i];
	
	 Find_maxi(nums , n , i+1 , max);
}

void Find_mini(vector<int>& nums , int& n , int i , int& min)
{
	if(i>=n)
		return;
	if(nums[i]<min)
		min=nums[i];
	
	Find_mini(nums , n , i+1 ,min);
}


int main()
{
	int n;
	cout<<"Enter the value of the element = ";
	cin>>n;
	vector<int>nums(n);
	for(int i=0; i<n; i++)
	{
		cin>>nums[i];
	}
	int max = INT_MIN;
	int min = INT_MAX;
	int i =0;
	cout<<"the maximus and minimum element is = "<<max<< " , "<<min<<endl;
	Find_maxi(nums , n , i , max);
	Find_mini(nums , n, i , min);
	cout<<"the maximus and minimum element is = "<<max<< " , "<<min<<endl;
	return 0;
}