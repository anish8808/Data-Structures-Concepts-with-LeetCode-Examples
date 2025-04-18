class Solution
{
public:
    bool solve(string &s, int si, string &p, int pi)
    {
        // base case

        if (si == s.size() && pi == p.size())
            return true;

        if (si == s.size() && pi < p.size())
        {
            while (pi < p.size())
            {
                if (p[pi] != '*')
                    return false;

                pi++;
            }

            return true;
        }

        // 1-case if both character is mathched or p[pi] is '?' then we will consider

        if (s[si] == p[pi] || p[pi] == '?')
        {
            return solve(s, si + 1, p, pi + 1);
        }

        if (p[pi] == '*')
        {
            // exclude * in the string by moiving one plus position
            bool caseA = solve(s, si, p, pi + 1);

            bool caseB = solve(s, si + 1, p, pi);

            return caseA || caseB;
        }

        // if both the above condition not matched the both char are diff we need to retunn as false
        return false;
    }

    bool isMatch(string s, string p)
    {
        int si = 0;
        int pi = 0;
        bool ans = solve(s, si, p, pi);

        return ans;
    }
};