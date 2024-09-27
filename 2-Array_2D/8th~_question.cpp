#include<iostream>

using namespace std;

void transposed_arrays(int arr[][3] , int transpose[][3] , int row , int col)
{
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            transpose[j][i]= arr[i][j];
        }
    }
}

void printArray(int arr[][3] , int row  , int col)
{
    for (int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main ()
{
    int arr[4][3]={{1 ,2 ,3} , {5 , 6 ,7 } ,{9 , 10 , 11 } , {12 ,13 , 14}};
    int transposed_array[4][3];

    int row = 4;
    int coloum = 3;

    transposed_arrays(arr , transposed_array , row  , coloum);

    printArray(transposed_array , row , coloum);

    
    return 0;
}