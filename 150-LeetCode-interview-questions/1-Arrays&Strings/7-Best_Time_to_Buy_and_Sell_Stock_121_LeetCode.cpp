
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int buyMoney = INT_MAX;
    int profit = INT_MIN;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < buyMoney)
        {
            buyMoney = prices[i];
        }
        int sellMoney = prices[i] - buyMoney;
        profit = max(profit, sellMoney);
    }

    return profit;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int ans = maxProfit(nums);
    cout << "The Maximum Profit is " << ans << endl;

    return 0;
}