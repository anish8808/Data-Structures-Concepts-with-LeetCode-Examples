// https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxarea = 0;
    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        maxarea = max(maxarea, area);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxarea;
}
int main()
{
    vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = maxArea(nums);
    cout << ans << endl;
}