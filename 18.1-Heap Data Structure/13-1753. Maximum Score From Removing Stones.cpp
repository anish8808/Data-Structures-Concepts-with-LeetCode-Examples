// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

// Heap solituion
/**
int maximumScore(int a, int b, int c) {
    priority_que<int>pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int ans =0;
    while(!pq.empty())
    {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        if(second>0)
        {
            ans ++;
            first--;
            second--;
        }
        if(first>0)
            pq.push(first);
        if(second>0)
            pq.push(second);
    }

    return ans;
}
**/
int maximumScore(int a, int b, int c)
{
    int minVal = min({a, b, c});
    int maxVal = max({a, b, c});
    int midVal = a + b + c - minVal - maxVal; // The middle number

    a = minVal, b = midVal, c = maxVal;
    int ans = 0;
    int sum = a + b;
    while (sum > c)
    {
        ans = ans + 1;
        a--;
        b--;
        sum = a + b;
    }

    ans = sum + ans;
    return ans;
}

int main()
{
    int a = 2, b = 4, c = 6;
    int nums = maximumScore(a, b, c);
    cout << nums << endl;
    return 0;
}