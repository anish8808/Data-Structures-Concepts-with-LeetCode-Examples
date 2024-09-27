
/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/




#include <bits/stdc++.h>

using namespace std;

int climbstairs(int n)
{
	if(n==0 || n==1){
		return 1;}
	
	return climbstairs(n-1)+climbstairs(n-2);
}


int main()
{
	int n ;
	cin>>n;
	cout<<"Enter the number for stairs  "<<endl;
	int ans = climbstairs(n);
	cout<<endl<<"the final ways will be =  " << ans << endl;
	return 0;
	
}