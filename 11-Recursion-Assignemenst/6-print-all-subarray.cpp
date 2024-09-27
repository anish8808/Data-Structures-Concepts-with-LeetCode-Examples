#include<bits/stdc++.h>

using namespace std ;

void PrintAllSubarray(vector<int> nums , int i , vector<int>ans )
{
    if(i>=nums.size())
        {
            cout<<" { ";
            for(auto val : ans)
            { 
                cout<<val<<" , ";
            }
            cout<<" } "<<endl;

            return ;
        }

   
    ans.push_back(nums[i]);
    PrintAllSubarray(nums , i+1 , ans);
    ans.pop_back();
    PrintAllSubarray(nums , i+1 , ans);

}

int main()
{
    vector<int>arr {1 , 2 , 3 , 4 , 5};
    vector<int>arr1;
    PrintAllSubarray(arr , 0 , arr1);
    return 0;
}