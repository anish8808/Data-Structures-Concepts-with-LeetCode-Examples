#include <bits/stdc++.h>

using namespace std;

void checkValidBST(vector<int> &A, int &i, int low, int high)
{
    if (i >= A.size())
        return;

    if (A[i] > low && A[i] < high)
    {
        int value = A[i];
        i++;
        checkValidBST(A, i, low, value);
        checkValidBST(A, i, value, high);
    }
}
int solve(vector<int> &A)
{
    int low = INT_MIN;
    int high = INT_MAX;
    int i = 0;
    checkValidBST(A, i, low, high);
    if (i >= A.size())
        return 1;
    else
        return 0;
}

int main()
{
    vector<int> preorder{8, 1, 2, 4, 9, 10, 11, 23};
    int ans = solve(preorder);
    cout << "ans - " << ans;
    return 0;
}