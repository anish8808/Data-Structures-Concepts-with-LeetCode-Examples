#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> digitString;
void solve(string &digits, vector<string> &ans, int i, string output)
{
    // base case
    if (i == digits.size())
    {
        ans.push_back(output);
        return;
    }

    // 1 case hum likh rhe hain
    string res = digitString['0' + i];
    for (int j = 0; j < res.size(); j++)
    {
        output = output + res[j];
        solve(digits, ans, i + 1, output);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    int i = 0;
    vector<string> ans;
    string output = "";
    digitString['2'] = "abc";
    digitString['3'] = "def";
    digitString['4'] = "ghi";
    digitString['5'] = "jkl";
    digitString['6'] = "mno";
    digitString['7'] = "pqrs";
    digitString['8'] = "tuv";
    digitString['9'] = "wxyz";
    solve(digits, ans, i, output);
    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("23");
    for (auto val : ans)
    {
        cout << val << endl;
    }
    return 0;
}