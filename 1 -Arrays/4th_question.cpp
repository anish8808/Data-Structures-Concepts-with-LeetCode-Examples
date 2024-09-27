#include<iostream>
#include<vector>

using namespace std;

int FindUniqueElement(vector <int> arr )
{
    int ans =0;
    for (int i=0; i<arr.size(); i++)
    {
        ans = ans^arr[i];
    }

    return ans;
}

int main()
{
    cout<<"Enter the size of the array " <<endl;
    int n;
    cin>>n;
    vector <int> arr(n);
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int result = FindUniqueElement(arr);
    cout<<"The element which is odd is "<< result<< endl;
    return 0;
}