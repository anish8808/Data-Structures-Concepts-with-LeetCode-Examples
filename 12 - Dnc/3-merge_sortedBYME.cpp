#include<bits/stdc++.h>

using namespace std ;

void merge2sortedArray(vector<int> & arr , int start , int end , int mid )
{
    vector<int> arr1 ;
    vector<int> arr2;
 
    //creating left array 
    for(int i = start ; i<=mid; i++)
        arr1.push_back(arr[i]);
    //  creatig Rigth Array
    for (int i = mid+1;  i<=end; i++)
    {
        arr2.push_back(arr[i]);
    }
    

    // merging 2 array 

    int i =0; int j = 0;

    // very important to keep this arrayindex from start beacuse we are doing changes in main Array
    int ArrayIndex = start;
    while(i<arr1.size()  && j< arr2.size())
    {
        if(arr1[i]>arr2[j])
        {
            arr[ArrayIndex]=arr2[j];
            j++;
            ArrayIndex++;
        }
        else
        {
            arr[ArrayIndex]=arr1[i];
            i++;
            ArrayIndex++;
        }
    }
    while(i<arr1.size())
    {
        arr[ArrayIndex]=arr1[i];
            i++;
            ArrayIndex++;
    }

    while(j<arr2.size())
    {
        arr[ArrayIndex]=arr2[j];
            j++;
            ArrayIndex++;
    }

}

void mergeSort(vector<int> &  arr , int start , int end)
{
    if(start>=end)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr , start , mid);
    mergeSort(arr , mid+1 , end);

    merge2sortedArray(arr , start , end , mid);
}

int main()
{
    vector<int>arr{4 , 1 ,3 ,5 ,6 ,2};
    int start =0; 
    int end =arr.size()-1;
    mergeSort(arr , start , end);
    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}