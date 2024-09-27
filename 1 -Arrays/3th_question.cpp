#include<iostream>

using namespace std;

int main(){

    int arr[10] = {0 , 1, 0 , 1, 1 , 3, 4 , 5, 2, 1};

    int result_one =0;
    int result_zero=0;
    for (int i=0; i<10; i++)
    {
        if(arr[i]==0)
            result_zero++;
        if(arr[i]==1)
            result_one++;
    }

    cout<<"the total number of zero and ones are "<<result_zero<<" "<<result_one<<endl;

}