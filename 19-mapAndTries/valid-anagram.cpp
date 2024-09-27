#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    string s = "Anish";
    string t = "nishA";

    for (int i = 0; i < s.length(); i++)
    {
        map1[s[i]]++;
        map2[t[i]]++;
    }

    if (map1 == map2)
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}