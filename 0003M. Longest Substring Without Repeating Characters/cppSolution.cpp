class Solution
{
public:
    Solution()
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> str;
        int ret = 0, slow = 0, n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (str.count(s[i]) != 0)
                slow = max(slow, str[s[i]] + 1);
            str[s[i]] = i;
            ret = max(ret, i - slow + 1);
        }
        return ret;
    }
};