#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[] , int size , int target , int start , int end)
{
    if(start>end)
        return -1;

    int mid = start + (end-start)/2;
    int ans = -1;

    if(arr[mid]==target)
        return mid;

    else if (arr[mid]>target)
       ans =  binarySearch(arr , size , target , start , mid-1);
    else
       ans = binarySearch(arr , size , target ,  mid+1 , end);

    return ans ;
}

int main()
{
    int arr [] = {2 ,4 , 6 ,8 ,10 , 12};
    int size = 6;
    int target = 12;

    int findIndex  = binarySearch(arr , size , target , 0 , 6);

    cout<<"the index of the target element is "<<findIndex<<endl;

    return 0; 

}