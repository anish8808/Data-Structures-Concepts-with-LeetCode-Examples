#include<iostream>

using namespace std;

int main()
{
    int arr[3][3]= {{1 ,2 ,3} , {4, 5 ,6} , {7 , 8 ,9}};
    int key =61;
    bool check = false ;
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (key == arr[i][j])
            {
                check = true;
            }
        }
    }

    if(check)
    {
        cout<<"The given Key is Present in the Array "<<endl;
    }
    else{
        cout<<"The given Key is not Present in the Array "<<endl;
    }
    return 0;
}