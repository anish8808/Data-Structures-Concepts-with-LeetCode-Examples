// https://leetcode.com/problems/happy-number/?envType=study-plan-v2&envId=top-interview-150
#include <bits/stdc++.h>

using namespace std;

long int new_val(long int val)
{
    long int sum = 0;
    int temp = 0;
    while (val != 0)
    {
        temp = val % 10;
        sum = sum + temp * temp;
        val = val / 10;
    }

    return sum;
}

bool isHappy(int n)
{
    long int val = n;
    unordered_map<int, int> mapp;
    while (val != 1 && mapp.count(val) == 0)
    {
        mapp[val]++;
        val = new_val(val);
    }

    cout << val << endl;
    return val == 1;
}
int main()
{
    int ans = isHappy(19);
    cout << ans << endl;

    return 0;
}