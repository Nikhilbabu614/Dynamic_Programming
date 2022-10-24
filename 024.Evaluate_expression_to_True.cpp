// Recursion ------
int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lT = solve(s, i, k - 1, true), lF = solve(s, i, k - 1, false);
        int rT = solve(s, k + 1, j, true), rF = solve(s, k + 1, j, false);
        if (s[k] == '&')
        {
            if (isTrue)
                ans = ans + lT * rT;
            else
                ans = ans + lF * rT + lF * rF + lT * rF;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans = ans + lT * rF + lF * rT + lT * rT;
            else
                ans = ans + lF * rF;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans = ans + lF * rT + lT * rF;
            else
                ans = ans + lF * rF + rT * lT;
        }
    }
    return ans;
}
int countWays(int N, string s)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return solve(s, 0, N - 1, true);
}




// Recursion with Memoized
int solve(string s, int i, int j, map<string,int> dp, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
    if (dp.find(temp) != dp.end())
        return dp[temp];
    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lT = solve(s, i, k - 1, dp, true), lF = solve(s, i, k - 1, dp, false);
        int rT = solve(s, k + 1, j, dp, true), rF = solve(s, k + 1, j, dp, false);
        if (s[k] == '&')
        {
            if (isTrue)
                ans = ans + lT * rT;
            else
                ans = ans + lF * rT + lF * rF + lT * rF;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans = ans + lT * rF + lF * rT + lT * rT;
            else
                ans = ans + lF * rF;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans = ans + lF * rT + lT * rF;
            else
                ans = ans + lF * rF + rT * lT;
        }
    }
    return dp[temp] = ans;
}
int countWays(int N, string s)
{
    map<string, int> m;
    return solve(s, 0, N - 1, m, true);
}