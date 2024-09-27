#include<bits/stdc++.h>

using namespace std ;


int partitionAlgo(vector<int> & arr , int start , int pivot)
{
    int i = start-1;
    int j = start;

    while(j<pivot)
    {
        if(arr[j]<arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i] , arr[pivot]);

    return i;
}

void QuickSort (vector<int> & arr , int start , int end)
{
    if(start>=end)
        return ;

    int pivot = end;

    pivot = partitionAlgo(arr , start , pivot);

    //calling for left side of the array
    QuickSort(arr , start , pivot-1);

    //calling for right side of the array 
    QuickSort(arr , pivot+1 , end);

}

int main()
{
    vector<int>arr{7 , 2 ,1 , 8 ,6 ,3 ,5, 4};
    int start =0; 
    int end =arr.size()-1;
    QuickSort(arr , start , end);
    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}