#include<bits/stdc++.h>

using namespace std ;

void merge2sort(int arr1[] , int arr2[] , int sizearr1 , int sizearr2 , vector<int> &nums)
{
    int i=0;
    int j=0;
    while(i<sizearr1 && j<sizearr2)
    {
        if(arr1[i]<arr2[j])
        {
            nums.push_back(arr1[i]);
            i++;
        }
        else
        {
            nums.push_back(arr2[j]);
            j++;
        }
    }

    while(i<sizearr1)
    {
        nums.push_back(arr1[i]);
        i++;
    }

    while(j<sizearr2)
    {
        nums.push_back(arr2[j]);
        j++;
    }
}

int main()
{
    int arr [] = {10 , 30 , 50 , 70};
    int sizearr = 4;
    int arr2[] = {20 ,40 , 60 , 80 , 90 , 100};
    int sizearr2 = 6;
     vector<int>nums ;
    merge2sort(arr , arr2 , sizearr , sizearr2 , nums);
    for(auto val : nums)
    {
        cout<<val <<" ";
    }
   
return 0;
}