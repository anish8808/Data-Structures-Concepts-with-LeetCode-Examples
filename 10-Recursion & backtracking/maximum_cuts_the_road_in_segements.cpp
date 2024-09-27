#include <bits/stdc++.h>

using namespace std ;


int solve(int n , int x , int y , int z)
{
	if(n==0)
		return 0;
	if(n<0)
		return INT_MIN;
	
	int maxi = INT_MIN;
	
	int ans1 = solve(n-x , x , y ,z);
	if(ans1!=INT_MIN)
		maxi = max(maxi , ans1+1);
	int ans2 = solve(n-y , x , y ,z);
	if(ans2!=INT_MIN)
		maxi = max(maxi , ans2+1);
	int ans3 = solve(n-z , x , y ,z);
	if(ans3!=INT_MIN)
		maxi = max(maxi , ans3+1);
	
	return maxi;
}

int main()
{
	int n =4; int x = 2; int y = 1; int z = 1;
	
	int ans = solve(n , x ,  y , z);
	if(ans<0)
		cout<<"there is ZERO cut possible"<<endl;
	else 
		cout<<"the maximum numbers of cuts will be = "<<ans<<endl;
	
	return 0;
}