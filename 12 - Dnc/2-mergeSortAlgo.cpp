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

void merge(int arr[] , int start , int end , int mid)
{
    int leftlen = mid-start +1;
    int rightLen = end-mid;

//create left and side right array
    int *leftarr = new int[leftlen];
    int *rightarr = new int[rightLen];

//fill the array 

int index =start;

//copying left
for(int i=0; i<leftlen; i++)
{
    leftarr[i] = arr[index];
    index++;
}
for(int i=0; i<rightLen; i++)
{
    rightarr[i] = arr[index]; 
    index++;
}

//merge logic 

int i =0;
int j= 0;
int mainArrayIndex = start;

while(i<leftlen && j<rightLen)
{
    if(leftarr[i]<rightarr[j])
    {
        arr[mainArrayIndex]= leftarr[i];
        i++;
        mainArrayIndex++;
    }
    else
    {
        arr[mainArrayIndex]= rightarr[j];
        j++;
        mainArrayIndex++;
    }
}

while (i<leftlen)
{
    arr[mainArrayIndex]= leftarr[i];
        i++;
        mainArrayIndex++;
}

while (j<rightLen)
{
    arr[mainArrayIndex]= rightarr[j];
        j++;
        mainArrayIndex++;
}

//
delete leftarr;

delete rightarr;

}

void mergeSort(int arr[] , int start , int end)
{
    if(start>=end)
        return ;
    
    int mid = (start + end)/2;

    mergeSort(arr , start , mid);
    mergeSort(arr , mid+1 , end);

    merge(arr , start , end , mid);
}

int main()
{
    int arr [] = {10 , 80 , 110 , 90 ,50 , 30 , 40 , 20};
    mergeSort(arr , 0 , 7);
   for(int i =0; i<8; i++)
   {
    cout<<arr[i]<<endl;
   }
   
return 0;
}