#include<iostream>

using namespace std;

int main()
{
    int arr[3][3]= {{1 ,2 ,3} , {4, 5 ,6} , {7 , 8 ,9}};
    int sum ;
    for (int i=0; i<3; i++)
    {
        sum =0;
        for(int j=0; j<3; j++)
        {
            sum += arr[j][i];
        }
        cout << "Sum of the "<<i<< " row is " <<sum <<endl;
    }
    return 0;
}