#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[] , int size , int target)
{
    int start =0; 
    int end = size-1;
    int mid = start + (end-start)/2;

    while(start<=end)
    {
        if(target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {   
            start = mid+1;
        }
        else {
            end = mid -1;
        }

       mid = start + (end-start)/2;
    }

    return -1;
}

int main()
{
    int arr [] = {2 ,4 , 6 ,8 ,10 , 12};
    int size = 6;
    int target = 10;

    int findIndex  = binarySearch(arr , size , target);

    cout<<"the index of the target element is "<<findIndex<<endl;

    return 0; 

}