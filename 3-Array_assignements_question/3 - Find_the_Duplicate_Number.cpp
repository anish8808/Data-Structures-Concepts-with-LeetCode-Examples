/*
LeetCode Problem - 287

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/



//Solution -1 
/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans =-1;
        for(int i=0; i<nums.size()-1; i++)
        {
            int index = abs(nums[i]);
            if(nums[index]<0)
            {
                ans = index ;
                break ;
            }

            //visited 

            nums[index] *= -1;
        }
    return ans ;
    }
};*/

//solution 2 

#include<iostream>
#include<vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
        int index =0;
        int ans = -1;
        for (unsigned long int i=0; i<nums.size(); i++)
        {
            if(nums[index]==nums[nums[index]])
            {
                ans = nums[index];
                break;
            }
            swap(nums[index] , nums[nums[index]]);
        }
        return ans ;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums ;
    for(int i=0; i<=n; i++)
    {
        cin>>nums[i];
    }

    int result = findDuplicate(nums);
    cout<<result<<endl;

    return 0;
}



