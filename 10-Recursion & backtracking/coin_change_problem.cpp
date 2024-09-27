#include <bits/stdc++.h>

using namespace std ;

int solve(vector<int> arr , int target)
{
	if(target ==0)
		return 0;
	if(target<0)
		return INT_MAX;
	
	int mini = INT_MAX;
	for(int i=0; i<arr.size(); i++)
	{
		int ans = solve(arr , target-arr[i]);
		if(ans!=INT_MAX)
		{
			mini = min(mini , ans+1);
		}
	}
	return mini;
}

int main()
{
	vector<int> arr{1 , 2 ,3};
	int target = 7;
	int ans = solve(arr , target);
	
	cout<<"Minimum coin needed to reach the target money is = "<<ans <<endl;
	return 0;
}