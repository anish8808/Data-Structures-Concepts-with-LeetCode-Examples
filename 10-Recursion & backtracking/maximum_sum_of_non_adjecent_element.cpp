#include <bits/stdc++.h>

using namespace std ;

int solve (vector<int>arr , int i , int output , int maxi)
{
	if(i>=arr.size())
		return output;
	
	//include karna hain
	
	int ans1 = solve(arr , i+2 , output+arr[i] , maxi);
	
	//exclude karna hai 
	
	int ans2 = solve(arr , i+1 , output , maxi);
	
    maxi = max(ans1 , ans2);
    cout<<"ans1 & ans2 is "<<ans1 <<" "<<ans2<< " = ";
    cout<<"MAXI is = "<<maxi<<endl;
    return maxi ;
}

int main()
{
	vector<int>arr{2,1,4,9};
	int output = 0;
	int maxi = INT_MIN;
	int i =0;
	int ans = solve(arr , i , output , maxi);
	
	cout<<"The maximun sum of the subarray that is " <<ans<<endl;
	
	return 0;
}