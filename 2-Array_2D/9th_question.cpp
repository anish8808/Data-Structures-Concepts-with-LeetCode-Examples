#include<iostream>
#include<vector>

using namespace std;

int main()
{
    // vector< vector<int> > ans;

    // vector<int> a;

    // vector<int> b ;
    
    // vector<int> c ;

    // a[0]=1 ; a[1]=1 ; a[2]=2;
    // b[0]=1 ; b[1]=1 ; b[2]=2;
    // c[0]=1 ; c[1]=1 ; c[2]=2;

     

    // ans.push_back(a);
    // ans.push_back(b);
    // ans.push_back(c);



    //another way of defineing


    vector< vector<int> > ans(4 ,vector<int>(5 ,0)); 


    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}