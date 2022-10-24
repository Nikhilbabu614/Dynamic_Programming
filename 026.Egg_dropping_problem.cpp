int solve(int e, int f, vector<vector<int>> &dp)
{
    if (f == 0 || f == 1 || e == 1)
        return f;
    int ans = INT_MAX;
    if (dp[e][f] != -1)
        return dp[e][f];
    for (int k = 1; k <= f; k++)
    {
        // max because of worst case -- break,not break
        int temp = 1 + max(solve(e - 1, k - 1, dp), solve(e, f - k, dp));
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}
int eggDrop(int e, int f)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return solve(e, f, dp);
}





// Memoized optimized
int solve(int e, int f, vector<vector<int>> &dp)
{
    if (f == 0 || f == 1 || e == 1)
        return f;
    int ans = INT_MAX;
    if (dp[e][f] != -1)
        return dp[e][f];
    for (int k = 1; k <= f; k++)
    {
        // max because of worst case
        int left, right;
        if (dp[e - 1][k - 1] != -1)
            left = dp[e - 1][k - 1];
        else
        {
            left = solve(e - 1, k - 1, dp);
            dp[e - 1][k - 1] = left;
        }
        if (dp[e][f - k] != -1)
            right = dp[e][f - k];
        else
        {
            right = solve(e, f - k, dp);
            dp[e][f - k] = right;
        }
        int temp = 1 + max(left, right);
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}
int eggDrop(int e, int f)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return solve(e, f, dp);
}