int countMin(string s1)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int x = s1.length(), y = s2.length();
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
    return x - dp[x][y];
}