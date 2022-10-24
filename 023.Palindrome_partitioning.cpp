// Recursion - memoized
bool isPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (isPalindrome(s, i, j))
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(s, i, k, dp) + solve(s, k + 1, j, dp) + 1;
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}
int palindromicPartition(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(s, 0, n - 1, dp);
}



// Recursion - memoized optimized
int solve(string s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
            left = solve(s, i, k, dp);
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = solve(s, k + 1, j, dp);
        ans = min(1 + left + right, ans);
    }
    return dp[i][j] = ans;
}
