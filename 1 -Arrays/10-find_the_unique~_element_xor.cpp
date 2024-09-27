#include <bits/stdc++.h>

using namespace std ;

int findUniqueElement(vector<int>&brr)
{
	int ans = brr[0];
	for(int i =1; i< brr.size(); i++)
	{
		ans = ans ^ brr[i];
	}
	return ans ;
}
int main()
{
	vector<int>arr{1,2,3,1,2,3,4,5,4 ,5 ,6};
	
	int result = findUniqueElement(arr);
	
	cout<<"find the unique element " << result <<endl;
	return 0;
}