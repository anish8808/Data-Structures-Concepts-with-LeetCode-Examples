#include<iostream>
#include<vector>

using namespace std;

void Sort_Zero_And_Ones(vector <int> &arr)
{
    int start = 0;
    int end = arr.size()-1;

    while(start<end)
    {
        if(arr[start]==1 && arr[end]==0)
        {
            swap(arr[start] , arr[end]);  
            start++;
            end--;
        }  
        
        if(arr[start]==0)
            start++;
        if(arr[end]==1)
            end--;

    }

}

int main()
{
    int size ;
    cout<<"Enter the size of the Array ";
    cin>>size;
    vector <int > arr(size);

    //inserting the Arrays 
    cout<<endl<<"Enter the elemant of the Arrays ";
    for (int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    Sort_Zero_And_Ones(arr);

    //Print the Vector 

    for(auto val : arr)
    {
        cout<<endl<<val<<" ";
    }


    return 0;
}