#include <bits/stdc++.h>

using namespace std;

void solve(int arr[], int index, int size)
{
    if (index == size)
        return;

    cout << arr[index];

    solve(arr, index + 1, size);
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int index = 0;
    solve(arr, index, size);
    return 0;
}