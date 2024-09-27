/* Given an array of length n consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s on the left side and 1s on the right side of the array.

Example 1:

Input:
n = 5
arr[] = {0, 0, 1, 1, 0}
Output: {0, 0, 0, 1, 1}
Explanation: 
After segregate all 0's on the left and 1's on the right modify array will be {0, 0, 0, 1, 1}.  */



#include<bits/stdc++.h>

using namespace std;



void segregate0and1(vector<int> &arr, int n) {
        int start =0;
        int end = n-1;
        int i=0;
        while(i!=end)
        {
            if(arr[i]==0)
            {
                swap(arr[i] , arr[start]);
                i++;
                start++;
            }
            else
            {
                swap(arr[i] , arr[end]);
                end--;
            }
        }
 }
 
 
 int main()
 {
 	int n;
 	cout<<"Enter the element in the Array "<<endl;
 	cin>>n;
 	vector<int>arr(n);
 	for(int i=0; i<n; i++)
 	{
 		cin>>arr[i];
 	}
 	segregate0and1(arr , n);
 
 	for(auto val : arr)
 		cout<<val<<" ";
 	return 0;
 	
 }