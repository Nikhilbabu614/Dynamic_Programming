string longestPalindrome(string s)
{
    int n = s.length(), reslen = -1;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i; // odd case
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > reslen)
            {
                reslen = r - l + 1;
                res = s.substr(l, reslen);
            }
            l--;
            r++;
        }
        l = i, r = i + 1; // even case ---- check both ways
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > reslen)
            {
                reslen = r - l + 1;
                res = s.substr(l, reslen);
            }
            l--;
            r++;
        }
    }
    return res;
}

// Time complexity -- n*(2*n) ~= n*n