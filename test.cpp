#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 10;
    vector<int> arr;
    while (n > 0)
    {
        int bit = n % 2;
        arr.push_back(bit); //-->"0101"
        n = n / 2;          //--> 5 --> 2 -->1
    }
    reverse(arr.begin(), arr.end());
    for (auto i : arr)
        cout << arr[i] << " ";
}