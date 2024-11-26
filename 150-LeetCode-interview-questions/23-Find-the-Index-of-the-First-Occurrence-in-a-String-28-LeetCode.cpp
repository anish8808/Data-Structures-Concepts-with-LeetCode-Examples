// 28. Find the Index of the First Occurrence in a String
// leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle)
{
    int i = 0;
    int j = 0;
    while (i <= haystack.size())
    {
        if (j == needle.size())
            return i - needle.size();
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j = 0;
        }
    }
    return -1;
}
int main()
{
    int ans = strStr("Anish", "Ani");
    cout << ans << endl;
}