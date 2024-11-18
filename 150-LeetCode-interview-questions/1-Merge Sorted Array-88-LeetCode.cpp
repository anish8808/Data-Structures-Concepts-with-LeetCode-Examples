#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int k = n + m - 1;
    int i = m - 1;
    int j = n - 1;
    while (j >= 0)
    {
        if (i >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
}

int main()
{
    vector<int> nums1{1, 2, 4, 0, 0, 0, 0};
    int m = nums1.size() - 4;
    vector<int> nums2{2, 4, 5, 6};
    int n = nums2.size();
    merge(nums1, m, nums2, n);
    for (auto i : nums1)
    {
        cout << i << " ";
    }
    return 0;
}