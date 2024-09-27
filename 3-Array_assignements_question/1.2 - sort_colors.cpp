#include<iostream>
#include<vector>

using namespace std;

void sortZerosOnesTwos(vector<int> & arr)
{
    int low , mid , high;
    low=mid=0;
    high = arr.size()-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low] , arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    }

}



int main()
{
    vector<int> nums(6);
    
    for(int i=0; i<6; i++)
    {
        cin>>nums[i];
    }


    sortZerosOnesTwos(nums);

    // Printing the Values of the vectors
    // for (auto val : nums)
    // {
    //     cout<<val<<" ";
    // }

    return 0;
}