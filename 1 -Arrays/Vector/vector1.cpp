#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //creating the vector 
    vector <int > arr ;

    // int ans = (sizeof(arr)/sizeof(int));
    // cout<<ans<<endl;

    // cout<< arr.size()<<endl;  //--> total element of the vector
    // cout<<arr.capacity() <<endl;  //--> total size of the vector


    //insert the element 

    arr.push_back(10);
    arr.push_back(20);

    //print the array 

    for (unsigned long i =0; i<arr.size(); i++)
    {
        cout<<arr[i]<<endl;
    }

    //creating at run time
    int n;
    cout<<"Enter the size of the vector " <<endl;
    cin>>n;
    vector <int > brr(n , 10);
    for (unsigned long i =0; i<brr.size(); i++)
    {
        cout<<brr[i]<<endl;
    }
    return 0;
}