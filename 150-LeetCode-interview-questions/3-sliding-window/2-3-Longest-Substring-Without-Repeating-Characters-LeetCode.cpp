
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mapp;
    int count = 0, max_char = 0, start = 0, end = 0;
    for (int end = 0; end < s.size(); end++)
    {
        char ch = s[end];

        // check if char is present in the map
        if (mapp.count(ch) && mapp[ch] >= start)
        {
            start = mapp[ch] + 1;
        }

        mapp[ch] = end;
        max_char = max(max_char, end - start + 1);
    }

    return max_char;
}

int main()
{
    string s = "abcabcdabf";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
}