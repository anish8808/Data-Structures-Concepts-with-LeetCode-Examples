#include<iostream>

using namespace std;

int main()
{
    int arr[3][3]= {{1 ,2 ,3} , {4 , 5 , 6} ,{7 , 8 ,9}};

    int max = INT32_MIN;
    int min = INT32_MAX;

    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if(arr[i][j]>max)
            {
                max = arr[i][j];
            }

            if(arr[i][j]<min)
            {
                min = arr[i][j];
            }
        }
    }

    cout <<"The maximum and minimum number of this Array is "<<max<<" "<<min<<endl;
    return 0;
}