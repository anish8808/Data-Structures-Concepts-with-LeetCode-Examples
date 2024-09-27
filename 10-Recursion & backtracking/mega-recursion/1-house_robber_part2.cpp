#include<bits/stdc++.h>\


using namespace std;

int solve(vector<int>nums , int index , int size)
{
    if(index>size)
        return 0;

    int ans1 = nums[index]+solve(nums , index+2 , size);
    int ans2 = solve(nums , index+1 , size);
    int final = max(ans1 , ans2);

    return final;
}

int main()
{
    vector<int> nums {1,2,3};
    int n = nums.size();
    int ans =0;
    if(n==1) //for handling single element (yaha humne galati kari the)
        ans =nums[0];
    else{
    int opt1 = solve(nums  , 0 , n-2);
    int opt2 = solve(nums  , 1, n-1);
    ans = max(opt1 , opt2);
    }

    cout<<"The thief will robber the maximum amount "<<ans;
    return 0;
}