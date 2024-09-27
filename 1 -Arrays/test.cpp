#include<iostream>
#include<vector>

using namespace std ;

string solve(vector<int> a)
{
    int n = a.size();
    sort(a.begin() , a.end());
    for(int i=0; i< n-1 ; i++)
    {
        if(a[i+1]% a[i] !=0)
        {
            return "No";
        }
    }
    return "Yes";
}


int main()
{
    int n ;
    cin>>n;
    vector<int>a(n);
    for(int i =0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<solve(a) <<endl;


return 0;
}