#include<iostream>

using namespace std;

int main(){

    int arr[7] = {-1 , 2 , -3 , 4 , -5 , 6 , 0};

    int low , high;

    low =0;
    high = 6;
//Dutche National Algorithm
    while(low<high)
    {
        if(arr[low]<0)
        {
            low++;
        }
        else if (arr[high]>=0)
        {
            high--;
        }
        else
        {
            swap(arr[low] , arr[high]);
            low++;
            high--;
        }
    }
     // Printing the Array 

     for(int i=0; i<7; i++)
     {
        cout<<arr[i]<<" ";
     }

    return 0;
}