// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

void heapfiy(vector<int> &ans, int n, int currentIndex)
{
    int largestIndex = currentIndex;
    int leftIndex = 2 * currentIndex + 1;
    int rigthIndex = 2 * currentIndex + 2;

    if (leftIndex < n && ans[leftIndex] > ans[largestIndex])
    {
        largestIndex = leftIndex;
    }
    if (rigthIndex < n && ans[rigthIndex] > ans[largestIndex])
    {
        largestIndex = rigthIndex;
    }

    if (largestIndex != currentIndex)
    {
        swap(ans[largestIndex], ans[currentIndex]);
        currentIndex = largestIndex;
        heapfiy(ans, n, currentIndex);
    }
}

void buildHeap(vector<int> &ans)
{

    int n = ans.size();

    for (int i = n / 2; i >= 0; i--)
        heapfiy(ans, n, i);
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here

    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(a[i]);

    for (int i = 0; i < m; i++)
        ans.push_back(b[i]);

    buildHeap(ans);

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 4, 5};
    vector<int> ans = mergeHeaps(a, b, 5, 5);
    return 0;
}