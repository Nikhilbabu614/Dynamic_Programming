// Recursion
int lcs(int x, int y, string s1, string s2)
{
    if (x <= 0 || y <= 0)
        return 0;
    if (s1[x - 1] == s2[y - 1])
    {
        return 1 + lcs(x - 1, y - 1, s1, s2);
    }
    else
        return max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
}



// Recursion - bottom-up
int lcsm(int x, int y, string s1, string s2, vector<vector<int>> dp)
{
    if (x == 0 || y == 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (s1[x - 1] == s2[y - 1])
        return dp[x][y] = 1 + lcsm(x - 1, y - 1, s1, s2, dp);
    else return dp[x][y] = max(lcsm(x - 1, y, s1, s2, dp), lcsm(x, y - 1, s1, s2, dp));
}



// Recursion - DP Top-Down
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}