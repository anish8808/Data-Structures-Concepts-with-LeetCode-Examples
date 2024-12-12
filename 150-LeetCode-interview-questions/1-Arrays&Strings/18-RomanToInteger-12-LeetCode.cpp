// 28. Find the Index of the First Occurrence in a String
// leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num)
{
    string ans = "";
    while (num != 0)
    {
        if (num >= 1000)
        {
            ans = ans + 'M';
            num = num - 1000;
        }
        else if (num >= 900)
        {
            ans = ans + 'C' + 'M';
            num = num - 900;
        }
        else if (num >= 500)
        {
            ans = ans + 'D';
            num = num - 500;
        }
        else if (num >= 400)
        {
            ans = ans + 'C' + 'D';
            num = num - 400;
        }
        else if (num >= 100)
        {
            ans = ans + 'C';
            num = num - 100;
        }
        else if (num >= 90)
        {
            ans = ans + 'X' + 'C';
            num = num - 90;
        }
        else if (num >= 50)
        {
            ans = ans + 'L';
            num = num - 50;
        }
        else if (num >= 40)
        {
            ans = ans + 'X' + 'L';
            num = num - 40;
        }
        else if (num >= 10)
        {
            ans = ans + 'X';
            num = num - 10;
        }
        else if (num >= 9)
        {
            ans = ans + 'I' + 'X';
            num = num - 9;
        }
        else if (num >= 5)
        {
            ans = ans + 'V';
            num = num - 5;
        }
        else if (num >= 4)
        {
            ans = ans + 'I' + 'V';
            num = num - 4;
        }
        else
        {
            ans = ans + 'I';
            num = num - 1;
        }
    }

    return ans;
}
int main()
{
    string ans = intToRoman(3222);
    cout << ans << endl;
}