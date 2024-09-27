#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int> map1;
    string s = "Anish";
    string t = "nish";

    for (int i = 0; i < s.length(); i++)
    {
        map1[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        if (map1.find(t[i]) == 0)
        {
            cout << "Invalid" << endl;
            return 0;
        }
        else
        {
            map1[t[i]]--;
        }
    }

    for (auto i : map1)
    {
        if (i.second > 0)
        {
            cout << "Invalid" << endl;
            return 0;
        }
    }

    cout << "Valid" << endl;

    return 0;
}