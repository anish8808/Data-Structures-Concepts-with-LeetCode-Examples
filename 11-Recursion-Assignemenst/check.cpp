#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n; i++)
        {
            int count =0;
            int num = i;
            while(num>0)
            {
                if((num&1)==1)
                {
                    count++;
                }

                num = num>>1;
            }
            ans.push_back(count);
        }
    return ans;
 }

int main()
{
    int a ;
    cin>>a;
    vector<int>ans = countBits(a);
    for(auto val : ans)
    {
        cout<<val<<endl;
    }
    return 0;
}