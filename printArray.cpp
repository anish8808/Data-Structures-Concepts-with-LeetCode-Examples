#include <bits/stdc++.h>

using namespace std;

void solve(int arr[], int index, int size)
{
    if (index == size)
        return;

    cout << arr[index];

    solve(arr, index + 1, size);
}

void solve2(int arr[], int index, int size)
{
    if (index == size)
        return;

    cout << arr[index];

    solve2(arr, ++index, size);
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int index = 0;
    solve2(arr, index, size);
    return 0;
}