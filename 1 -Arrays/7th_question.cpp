#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int arr1[4] = {1 ,1 ,4  ,5};
    int arr2[4] = {4 ,4 ,1 ,1};


    vector <int> ans ;


    for (int i=0; i<4; i++)
    {
        int element = arr1[i];

        for (int j=0; j<4; j++)
        {
            if (arr2[j]==element)
            {
                arr2[j]=INT32_MIN;
                break;
            }
        }
    }
    for (int i=0; i<4; i++)
    {
        if(arr1[i]!=INT32_MIN)
        ans.push_back(arr1[i]);
    }

    for (int i=0; i<4; i++)
    {
        if(arr2[i]!=INT32_MIN)
        ans.push_back(arr2[i]);
    }

    //Printing the vector 

    for (auto value : ans )
    {
        cout<<value<<" ";
    }



    return 0;
}