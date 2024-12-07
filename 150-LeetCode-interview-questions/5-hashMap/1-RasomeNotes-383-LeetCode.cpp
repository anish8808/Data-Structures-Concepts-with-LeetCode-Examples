#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<int, int> map;
    for (int i = 0; i < magazine.size(); i++)
    {
        map[magazine[i]]++;
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
        if (map[ransomNote[i]] <= 0)
            return false;

        map[ransomNote[i]]--;
    }
    return true;
}

int main()
{
    bool ans = canConstruct("ans", "anishahia");
    cout << ans << endl;

    return 0;
}