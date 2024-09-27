#include<iostream>

#include<vector>

using namespace std ;

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int brr[3] = {3, 4, 5};
    vector <int > ans ;
    for (int i =0; i<5; i++)
    {
        int element = arr[i];
        for (int j=0; j<3; j++)
        {
            if (element==brr[j])
            {
                brr[j]=-1;
                ans.push_back(element);
            }
        }
    }

    //print the resulting array

    for (auto value : ans)
    {
        cout<<value<<" ";
    }

    return 0;
}
