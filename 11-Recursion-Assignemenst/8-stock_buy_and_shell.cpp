#include<bits/stdc++.h>

using namespace std ;

void solve(vector<int>arr , int start , int &min_price, int &max_profit)
{
   if(start>=arr.size())
       return ;

    //to calculate minimum price stock
    if(arr[start]<min_price)
        min_price  = arr[start];

    //to calculate maximum profit
    if(arr[start]-min_price>max_profit)
        max_profit = arr[start]-min_price;

    solve(arr , start+1 , min_price , max_profit);
}

int main()
{
    vector<int>arr {7 , 1, 5 ,3 , 7 ,4};
    int min_price = INT_MAX;
    int max_profit = INT_MIN;
    solve(arr , 0 , min_price , max_profit);
    cout<<"The Maxi is "<<max_profit<<endl;
    return 0;
}