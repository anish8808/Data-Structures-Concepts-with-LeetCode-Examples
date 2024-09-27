#include<bits/stdc++.h>

using namespace std ;

void solve (vector<int> ans , int start , int end)
{
    if(end>=ans.size())
        return ;
    
    for(int i = start; i<=end; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    solve(ans , start , end+1);
}

int main()
{
    vector<int>arr{1 ,2 , 3 , 4 , 5};
    int end =0;
    for(int i=0; i<arr.size(); i++)
    {
        end =i;
        solve (arr , i , end);
        cout<<endl;
    }

    return 0;
}