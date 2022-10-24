// 1 . Binary Tree
// 2 . No empty Node
// 3 . Swap one or more -- Non-leaf Nodes and make second string

bool isScramble(string s1, string s2)
{
    if (s1 == s2)
        return true;
    if (s1.length() <= 1 || s1.length() != s2.length())
        return false;
    int n = s1.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        bool f1 = isScramble(s1.substr(0, i), s2.substr(n - i, i)) 
            && isScramble(s1.substr(i, n - i), s2.substr(0, n - i));
        bool f2 = isScramble(s1.substr(0, i), s2.substr(0, i))
             && isScramble(s1.substr(i, n - i), s2.substr(i, n - i));
        if (f1 || f2)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

// Memoized version
bool solve(string s1, string s2, map<string, bool> &m)
{
    if (s1 == s2)
        return true;
    if (s1.length() <= 1 || s1.length() != s2.length())
        return false;
    int n = s1.length();
    string key = s1 + " " + s2;
    if (m.find(key) != m.end())
        return m[key];
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        bool f1 = solve(s1.substr(0, i), s2.substr(n - i, i), m) 
            && solve(s1.substr(i, n - i), s2.substr(0, n - i), m);
        bool f2 = solve(s1.substr(0, i), s2.substr(0, i), m)
            && solve(s1.substr(i, n - i), s2.substr(i, n - i), m);
        if (f1 || f2)
        {
            flag = true;
            break;
        }
    }
    return m[key] = flag;
}
bool isScramble(string s1, string s2)
{
    map<string, bool> m;
    return solve(s1, s2, m);
}