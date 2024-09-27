#include<iostream>


using namespace std ;

int main()
{
    int arr[7] = {1 , 2  ,3 , 4 ,5, 6,7};
    int start =0;
    int end = 6;
    while(start<=end)
    {
        if(start==end)
        {
            cout<<arr[start]<<" ";
            break;
        }
        cout<<arr[start]<<" "<<arr[end]<<" ";
        start++;
        end--;
    }


    return 0;
}