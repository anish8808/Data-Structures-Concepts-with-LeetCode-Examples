#include <bits/stdc++.h>

using namespace std;

void solve(string &str, string &part)
{
    if (str.find(part) == string::npos)
        return;

    int pos = str.find(part);
    string left_side = str.substr(0, pos);
    string right_side = str.substr(pos + part.length(), str.length());
    str = left_side + right_side;
    // this will be alternate solutions
    //  str.erase(pos , part.length());
    // this will be alternate solutions
    // str.erase(pos , part.length());
    return solve(str, part);
}

int main()
{
    string str, part;

    cout << "Enter the string and part that you want to remove";
    cin >> str >> part;

    solve(str, part);

    cout << "The final Strig will be " << str << endl;

    return 0;
}