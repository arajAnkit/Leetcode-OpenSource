class Solution
{
public:
    Solution()
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    // Solutin 1 - Brute Force

    string longestPalindrome(string s)
    {
        int n = s.size(), l = 0;
        string p;
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (p.size() < r - l + 1)
                {
                    p = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (p.size() < r - l + 1)
                {
                    p = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
        }

        return p;
    }
};