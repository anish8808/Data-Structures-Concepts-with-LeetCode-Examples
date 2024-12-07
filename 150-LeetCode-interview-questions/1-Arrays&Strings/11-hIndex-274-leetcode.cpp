// https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
#include <bits/stdc++.h>

using namespace std;

int hIndex(vector<int> &citations)
{
    int hIndex = INT_MIN;
    if (citations.size() == 1)
        return 1;
    for (int i = 0; i < citations.size(); i++)
    {
        int release = 0;
        for (int j = i; j < citations.size(); j++)
        {
            if (citations[j] >= citations[i])
                release++;
        }
        if (citations[i] <= release)
        {
            hIndex = max(hIndex, citations[i]);
        }
    }

    return hIndex;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int ans = hIndex(nums);
    cout << "Minimun jump Possible--> " << ans << endl;

    return 0;
}