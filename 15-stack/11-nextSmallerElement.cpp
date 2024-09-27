#include <bits/stdc++.h>
#include <stack>
using namespace std;

void solve(stack<int> &st, vector<int> &ans)
{
    int n = ans.size();
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (ans[i] < st.top())
        {
            st.pop();
        }
        int val = ans[i];
        ans[i] = st.top();
        st.push(val);
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    stack<int> st;
    solve(st, arr);
    for (auto it : arr)
    {
        cout << it << endl;
    }
    return 0;
}