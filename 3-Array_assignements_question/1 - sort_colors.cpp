#include<iostream>
#include<vector>

using namespace std;

int sortZeros(vector<int> &arr)
{
        int start = 0;
        int end = arr.size()-1;
        while(start<end)
        {
            if(arr[end]==0)
            {
                if(arr[start]==1 || arr[start]==2)
                    {
                        swap(arr[start] , arr[end]);
                        end--;
                    }
            }
            if(arr[start]==0)
                start++;
            if(arr[end]==1 || arr[end]==2)
                end--;
        }
        
        return start;

}

void sortOnes(vector<int>&num, int start) {
    if (num[start] == 0) {
        start++;
    }

    int end = num.size() - 1;

    while (start <= end) {
        if (num[end] == 1) {
            if (num[start] == 2) {
                swap(num[start], num[end]);
                end--;
                start++;
            }
            else {
                start++;
            }
        }

        if (num[start] == 1) {
            start++;
        }
        
        if (num[end]==2)
        {
            end--;
        }
    }
}



int main()
{
    vector<int> nums(2);
    
    for(int i=0; i<2; i++)
    {
        cin>>nums[i];
    }
    int index1 = sortZeros(nums);
    sortOnes(nums , index1);

    cout<<"the index is "<< index1 <<endl;

    for (auto val : nums)
    {
        cout<<val<<" ";
    }

    return 0;
}