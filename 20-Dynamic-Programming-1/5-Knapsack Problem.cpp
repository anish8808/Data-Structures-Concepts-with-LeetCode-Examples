#include <bits/stdc++.h>

using namespace std;

int solve(int capacity, vector<int> &val, vector<int> &wt, int index)
{
    // basecase
    if (index == 0)
    {
        if (capacity >= wt[index])
        {
            return val[index];
        }
        else
        {
            return 0;
        }
    }

    int inc = 0;
    if (capacity >= wt[index])
    {
        inc = val[index] + solve(capacity - wt[index], val, wt, index - 1);
    }
    int exec = 0 + solve(capacity, val, wt, index - 1);

    int final = max(inc, exec);

    return final;
}

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    // code here
    int index = wt.size() - 1;
    int ans = solve(W, val, wt, index);

    return ans;
}

int main()
{
    vector<int> val{1, 2, 4};
    vector<int> wt{4, 5, 6};
    int ans = knapsack(4, val, wt);
    cout << ans << endl;
    return 0;
}
